# FP_1806187783-1806228253_MuhammadGaviarsha-MochammadRivaldi

This project is about Contact Manager, we can perform 5 function. Such as Adding a New Contact, Deleting a contact, Listing all registrated contact, Modifying a contact, and finding a contact by name. The project use linked list as basic structure of the program.

The struct function as the content on the contact, the struct is used so we can modify the linked list easier. The struct in this program is using char because its using the character. and struct contact*next is used to navigate through structures

![1576229573224](https://user-images.githubusercontent.com/58845015/70790601-02735900-1dc8-11ea-8749-11e3001d920d.jpg)

so in this program we using switch case for directing the menu into 5 category and after we done with the program press Q to save and exit.

1. Adding a New Contact Function

![1576229722163](https://user-images.githubusercontent.com/58845015/70790891-862d4580-1dc8-11ea-93d4-3dee1d89ade0.jpg)

in this function we first allocate the memory for the linked list, the memory is dynamic according to the size of linked list and after that we use linked list to add the name, phone number, email and address of the contact. If the contact is successfully added it will show the text "contact added!"

2. Deleting a Contact

![1576229917604](https://user-images.githubusercontent.com/58845015/70791092-f8058f00-1dc8-11ea-84d9-800f22b9ac00.jpg)

In delete contact function, first we check if there are any contact in the file. If there are no contact it will show the text "There are no contact to delete!", and if there are any contact it will check the currentc variable then delete based on the number of the contact that we want to remove.

3. Listing All Registrated Contact

![1576229793127](https://user-images.githubusercontent.com/58845015/70790974-b1b03000-1dc8-11ea-9462-236b31a8fa6f.jpg)

In this function we use linked list currentc variable to the number,name,phone,email, and address to show the all data of the contact.

4. Modifying a Contact

![1576229851698](https://user-images.githubusercontent.com/58845015/70791032-d0162b80-1dc8-11ea-88a8-1a73108f8232.jpg)

In this function, we first check the availability of the firstc variable. If there are no contact in the file/program it will show the text "There are no contact to modify!" and if there are any contact in the program we can use the number of the contact to find the contact we want to modify. After that the program will use prompt function to check each linked list to modify.

5. Finding a Contact By Name

![1576229886857](https://user-images.githubusercontent.com/58845015/70791055-df957480-1dc8-11ea-874d-c53b506aee19.jpg)

In this function, the findcontact function is using the name to find the desired contact. So function will check the firstc variable to check the availabilty of the contact in the file, if there are none it will show "There are no contacts to find!" and if there are contact in the program it will chect the currentc variable and using strcmp (string compare) to find the desired contact using the name struct.


You can save the contact after we done with the program. The contactdatabase.dat will be modified after each change, and if we start the program again the file will be continued from latest change.

![1576231042609](https://user-images.githubusercontent.com/58845015/70791577-f092b580-1dc9-11ea-8a76-4cceea6e6b80.jpg)
