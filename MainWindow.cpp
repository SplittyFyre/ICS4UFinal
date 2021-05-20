#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QComboBox>
#include <QMessageBox>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    // do some Qt setup:
    ui->setupUi(this);
    this->setCentralWidget(ui->tabWidget);

    for (int i = 10; i <= 50; i++) { // fill combo-box with desired choices
        findChild<QComboBox*>("flightSeatsEdit")->addItem(QString::number(i));
    }

    loadDataBases();
}

MainWindow::~MainWindow() {
    delete ui;
}

// called when user attempts to add flight
// checks for the validity of the operation (are all the required boxes filled? does the flight already exist?)
void MainWindow::on_addFlightButton_released() {
    QLabel *status = findChild<QLabel*>("addFlightStatus");
    QString id = findChild<QLineEdit*>("flightIdEdit")->text().trimmed();
    int numSeats = findChild<QComboBox*>("flightSeatsEdit")->currentText().toInt();

    if (id.isEmpty()) {
        status->setText("Error: FlightID is empty");
        return;
    }

    Flight *flight = new Flight(id.toStdString(), numSeats);
    if (flights.contains(flight)) {
        status->setText("Error: flight already exists");
        delete flight;
        return;
    }
    flights.insert(flight);
    saveDataBases();
    status->setText("Flight '" + id + "' successfully added");
    findChild<QLineEdit*>("flightIdEdit")->clear();
}

// called when user attempts to remove flight
// check for the validity of the operation (are all the required boxes filled? does the flight even exist?)
void MainWindow::on_removeFlightButton_released() {
    QLabel *status = findChild<QLabel*>("removeFlightStatus");
    QString id = findChild<QLineEdit*>("rflightIdEdit")->text().trimmed();

    if (id.isEmpty()) {
        status->setText("Error: FlightID is empty");
        return;
    }

    // we can allocate this on the stack and use the constructor that leaves its heap memory uninitialized
    // since it doesnt actually store anything, its used only to search the RBTree via comparisons
    Flight key(id.toStdString()); // there will be more instances of objects used like this later on
    if (!flights.contains(&key)) {
        status->setText("Error: flight doesn't exist");
        return;
    }

    // before erasing flight, remove all customers who booked this flight:
    Flight *flight = dynamic_cast<Flight*>(flights.get(&key));
    for (int i = 0; i < flight->getSize(); i++)
        if (flight->getSeat(i) != nullptr)
            customers.erase(flight->getSeat(i));

    flights.erase(&key);
    saveDataBases();
    status->setText("Flight '" + id + "' successfully removed");
    findChild<QLineEdit*>("rflightIdEdit")->clear();
}

// called when user queries a flight
// check for the validity of the operation and return information regarding seats on requested flight
void MainWindow::on_queryFlightButton_released() {
    QPlainTextEdit *output = findChild<QPlainTextEdit*>("queryFlightOutput");
    QString id = findChild<QLineEdit*>("queryFlightIdEdit")->text().trimmed();

    output->clear();
    if (id.isEmpty()) {
        output->appendPlainText("Error: FlightID is empty");
        return;
    }

    Flight key(id.toStdString()); // another key object
    if (!flights.contains(&key)) {
        output->appendPlainText("Error: flight doesn't exist");
        return;
    }
    if (!sortByName)
        output->appendPlainText(QString::fromStdString(dynamic_cast<Flight*>(flights.get(&key))->toString(showOccupiedOnly)));
    else
        output->appendPlainText(QString::fromStdString(dynamic_cast<Flight*>(flights.get(&key))->toSortedString()));

    findChild<QLineEdit*>("queryFlightIdEdit")->clear();
}

// called when checkbox for showing only occupied seats is changed
void MainWindow::on_cbOccupied_stateChanged(int arg1) {
    showOccupiedOnly = (arg1 == Qt::Checked); // update our flag
    if (arg1 == Qt::Unchecked) { // if this is unchecked, then it implies not sorting by name
        sortByName = false;
        findChild<QCheckBox*>("cbSorted")->setChecked(false); // uncheck sorting checkbox
    }
}

// called when checkbox for sorting passengers on flight by name is changed
void MainWindow::on_cbSorted_stateChanged(int arg1) {
    sortByName = (arg1 == Qt::Checked); // update our flag
    if (arg1 == Qt::Checked) { // if this is checked, it implies that we must only show occupied seats
        showOccupiedOnly = true;
        findChild<QCheckBox*>("cbOccupied")->setChecked(true); // check other box
    }
}

// called when user attempts to add a customer reservation
// checks for validity of the operation
void MainWindow::on_addCustomerSubmit_released() {
    QLabel *status = findChild<QLabel*>("addCustomerStatus");
    QString flightId = findChild<QLineEdit*>("addCustomerFlightId")->text().trimmed();
    int seatNum = findChild<QSpinBox*>("addCustomerSeatNum")->value();

    if (flightId.isEmpty()) {
        status->setText("Error: FlightID is empty");
        return;
    }

    Flight key(flightId.toStdString()); // another key object
    if (!flights.contains(&key)) {
        status->setText("Error: flight doesn't exist");
        return;
    }
    Flight *flight = dynamic_cast<Flight*>(flights.get(&key));
    if (seatNum >= flight->getSize()) {
        status->setText("Error: seat number can be at most " + QString::number(flight->getSize() - 1));
        return;
    }
    if (flight->getSeat(seatNum) != nullptr) {
        status->setText("Error: seat already taken");
        return;
    }

    QString name = findChild<QLineEdit*>("addCustomerName")->text().trimmed();
    QString address = findChild<QLineEdit*>("addCustomerAddress")->text().trimmed();
    QString phonenum = findChild<QLineEdit*>("addCustomerPhoneNum")->text().trimmed();
    if (name.isEmpty()) {
        status->setText("Error: customer name is empty");
        return;
    }
    if (address.isEmpty()) {
        status->setText("Error: customer address is empty");
        return;
    }
    if (phonenum.length() < 14) {
        status->setText("Error: customer phone number is incomplete");
        return;
    }

    Customer *customer = new Customer(name.toStdString(), address.toStdString(), phonenum.toStdString(), flightId.toStdString(), seatNum);
    if (customers.contains(customer)) {
        status->setText("Error: customer already has reservation");
        delete customer;
        return;
    }
    customers.insert(customer);
    flight->setSeat(seatNum, customer);
    saveDataBases();
    status->setText("Reservation successfully added");

    findChild<QLineEdit*>("addCustomerFlightId")->clear();
    findChild<QLineEdit*>("addCustomerName")->clear();
    findChild<QLineEdit*>("addCustomerAddress")->clear();
    findChild<QLineEdit*>("addCustomerPhoneNum")->clear();
}

// called when user submits a query to find a customer's reservation
// checks for the validity of the operations and shows a popup window which allows the user to delete the reservation
void MainWindow::on_findCustomerSubmit_released() {
    QLabel *status = findChild<QLabel*>("findCustomerStatus");

    QString name = findChild<QLineEdit*>("findCustomerName")->text().trimmed();
    QString phonenum = findChild<QLineEdit*>("findCustomerPhoneNum")->text().trimmed();
    if (name.isEmpty()) {
        status->setText("Error: customer name is empty");
        return;
    }
    if (phonenum.length() < 14) {
        status->setText("Error: customer phone number is incomplete");
        return;
    }

    findChild<QLineEdit*>("findCustomerName")->clear();
    findChild<QLineEdit*>("findCustomerPhoneNum")->clear();
    status->clear();

    Customer key(name.toStdString(), phonenum.toStdString()); // another key object
    if (!customers.contains(&key)) {
        status->setText(name + " has no reservation");
    }
    else {
        Customer *customer = dynamic_cast<Customer*>(customers.get(&key)); // full customer info

        // information about the customers reservation (QString::arg formats the string kinda like printf):
        QString info = QString("Customer %1 has reserved Seat # %2 on flight %3\nWould you like to delete it?")
                .arg(QString::fromStdString(customer->getName()), QString::number(customer->getSeatNum()), QString::fromStdString(customer->getFlightId()));

        // prompt user with message box:
        QMessageBox mbox;
        mbox.setWindowTitle("Reservation");
        mbox.setText(info);
        mbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        mbox.setDefaultButton(QMessageBox::No);
        auto action = mbox.exec(); // does user want to delete or not?

        if (action == QMessageBox::Yes) { // user wants to delete the reservation
            // we first need to find the flight that this customer is on and clear their seat
            Flight key2(customer->getFlightId()); // another key object
            Flight *flight = dynamic_cast<Flight*>(flights.get(&key2));
            flight->setSeat(customer->getSeatNum(), nullptr);

            customers.erase(customer);
            saveDataBases();
            status->setText("Reservation successfully deleted");
        }
    }
}

// given a Record, cast it to a Customer and mark that Customer's seat as occupied
void MainWindow::loadDataHelper(Record *r) {
    Customer *customer = dynamic_cast<Customer*>(r);
    Flight key(customer->getFlightId()); // another key object
    Flight *flight = dynamic_cast<Flight*>(flights.get(&key));
    flight->setSeat(customer->getSeatNum(), customer);
}

void MainWindow::loadDataBases() {
    // load flights:
    std::ifstream fin("data/data.dat");
    if (!fin.good()) return; // return if the file doesnt exist

    Flight tmp("whatever"); // an arbitrary Flight instance, doesnt store anything, ensures that RBTree::load creates the correct type
    flights.load(fin, &tmp);

    Customer tmp2; // an arbitrary Customer instance, doesnt store anything, ensures that RBTree::load creates the correct type
    customers.load(fin, &tmp2);

    // due to the difficulties of writing pointers to the disk, we do not save the 'seats' data member of the Flight class
    // which means that at this point in the code, the flights dont contain the proper seating information
    // we must go through all customers and update their corrosponding flight
    // note: this weird notation is a lambda expression which is necessary in order to pass a non-static member function as an argument
    customers.forEach([this](Record *r) { this->loadDataHelper(r); });
}

void MainWindow::saveDataBases() {
    std::ofstream fout("data/data.dat");
    flights.save(fout);
    customers.save(fout);
}
