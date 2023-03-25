# Payment_Application
This project is a simulation of a payment system that allows customers to make purchases using their bank accounts. It focuses on implementing the SALE transaction by simulating the card, terminal (ATM), and server.

Technologies Used
C and standered c libraries 

Project Description: 
Request the PIN code from the customer
Check the card balance
Deduct the purchase amount from the card balance
Return a confirmation code to the terminal
The terminal module is responsible for simulating the ATM used by the customer to make the purchase. 

It includes the following functionalities:
Request the card information from the customer:
Request the purchase amount from the customer
Send the purchase request to the server
The server module is responsible for processing the purchase request sent by the terminal. It should include the following functionalities:

Verify the card information:
Verify the card balance
Process the purchase request
Generate a confirmation code

The application should bring together the card, terminal, and server modules to simulate the SALE transaction. It should allow the user to interact with the system by entering the card information, the purchase amount, and the PIN code.

Testing the Application:
To test the application, you can run it in the terminal and follow the prompts to simulate a SALE transaction. You should verify that the card balance is correctly updated and that a confirmation code is generated.

Conclusion:
This project provides a basic implementation of a payment system by simulating the card, terminal, and server modules. It can be extended to include additional transaction types and functionalities.
