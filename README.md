# Pet-Shop-Management-System

**Gowtham Pet Shop Management System**

This project is a simple Pet Shop Management System designed in C. It allows users to manage various aspects of a pet shop, such as pet care, essentials, hostel, food, and grooming. It features a basic login system and options to handle customer details and purchase details efficiently.

**Features:**

- **Customer Management:**
  - New customers can sign up with their details.
  - Existing customers can log in using their name, ID, and mobile number.
  - Customer records are saved to a file (records.txt) and a separate bill file (bill.txt) is generated for each purchase.
    
- **Service Options:**
  - The program provides the following options to the user:
    - **Pet Care:** Choose from a variety of pet care services.
    - **Pet Essentials:** Purchase essential products for pets.
    - **Pet Hostel:** Hostel service for pets.
    - **Pet Food:** Purchase food for pets.
    - **Pet Grooming:** Avail grooming services for pets.
      
- **Billing:**
  - A bill is generated based on the selected services or products.
    
- **File Handling:**
  - The program writes customer details to a `records.txt` file and generates a `bill.txt` file with a summary of the customer's purchases.
  - The file operations ensure that new customers can sign up and existing customers can log in seamlessly.
 
**Functions:**
- `petcare()`: Handles the logic for selecting pet care services.
- `petessential()`: Manages the purchase of pet essential products.
- `pethostel()`: Provides options for pet hostel services.
- `petfood()`: Allows the user to buy food for pets.
- `petgrooming()`: Offers grooming services for pets.
- 
**Future Enhancements:**
- Add a graphical user interface (GUI) to improve usability.
- Implement a database system for better storage and retrieval of customer and sales records.

  
