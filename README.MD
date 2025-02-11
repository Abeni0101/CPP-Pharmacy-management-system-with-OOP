# Pharmacy Management System

## Overview
The Pharmacy Management System is a C++ application designed to help manage a pharmacy's inventory and customer orders. It allows employees to modify, delete, and review orders while providing customers with an interface to purchase medicines and leave feedback.

## Features
- **Employee Section**
  - Modify order list
  - Delete medicine orders
  - View medicine information in store
  - View order summary
  - Review customer feedback
- **User Section**
  - Purchase medicines
  - Receive transaction receipts
  - Leave feedback
- **Data Storage**
  - Order summaries are saved in `summary.txt`
  - Customer feedback is saved in `feedback.txt`

## Installation and Setup
1. Ensure you have a C++ compiler installed (e.g., GCC, MSVC).
2. Copy the source code into a file named `pharmacy_management.cpp`.
3. Compile the program using a command such as:
   ```sh
   g++ pharmacy_management.cpp -o pharmacy_management
   ```
4. Run the program:
   ```sh
   ./pharmacy_management
   ```

## Usage
1. **Start the program**: Upon launching, you will be presented with options to enter either the employee or user section.
2. **Employee Login**: Employees must enter their ID and passcode (`1111` by default) to access management functions.
3. **User Interaction**:
   - View available medicines
   - Place an order and receive a receipt
   - Leave feedback on the system
4. **Exit**: The system allows users to exit gracefully.

## File Management
- `summary.txt` stores order details for record-keeping.
- `feedback.txt` logs customer feedback for review.

## Limitations
- The employee password is hardcoded as `1111`.
- The inventory is predefined within the code and does not support dynamic storage updates.

## Future Improvements
- Implement a database system for better inventory and order management.
- Enhance security by encrypting employee credentials.
- Improve UI for a more user-friendly experience.

## Author
Developed as a Pharmacy Management System project using C++.

## License
This project is open-source and available for modification and enhancement.