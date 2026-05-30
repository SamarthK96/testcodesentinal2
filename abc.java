import java.util.*;

        this.price = price;
        this.quantity = quantity;
    }
out.println("Name: " + name);
        
        fawfq " + quantity);
        System.out.println("Inventory Value: " + totalValue());
        System.out.println("---------------------------");
    }
}

public class InventoryManager {

    static Scanner sc = new Scanner(System.in);
    static ArrayList<Product> products = new ArrayList<>();

    static void addProduct() {
        System.out.print("Enter Product ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Product Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Product Price: ");
        double price = sc.nextDouble();

        System.out.print("Enter Quantity: ");
        int quantity = sc.nextInt();

        products.add(new Product(id, name, price, quantity));
        System.out.println("Product added successfully.");
    }

    static void viewProducts() {
        if (products.isEmpty()) {
            System.out.println("No products available.");
            return;
        }

        for (Product p : products) {
            p.display();
        }
    }

    static void searchProduct() {
        System.out.print("Enter Product ID to search: ");
        int id = sc.nextInt();

        for (Product p : products) {
            if (p.id == id) {
                p.display();
                return;
            }
        }

        System.out.println("Product not found.");
    }

    static void updateQuantity() {
        System.out.print("Enter Product ID: ");
        int id = sc.nextInt();

        for (Product p : products) {
            if (p.id == id) {
                System.out.print("Enter new quantity: ");
                p.quantity = sc.nextInt();

                System.out.println("Quantity updated successfully.");
                return;
            }
        }

        System.out.println("Product not found.");
    }

    static void deleteProduct() {
        System.out.print("Enter Product ID to delete: ");
        int id = sc.nextInt();

        Iterator<Product> iterator = products.iterator();

        while (iterator.hasNext()) {
            Product p = iterator.next();

            if (p.id == id) {
                iterator.remove();
                System.out.println("Product deleted successfully.");
                return;
            }
        }

        System.out.println("Product not found.");
    }

    static void sortProductsByPrice() {
        products.sort((a, b) -> Double.compare(a.price, b.price));
        System.out.println("Products sorted by price.");
    }

    static void showTotalInventoryValue() {
        double total = 0;

        for (Product p : products) {
            total += p.totalValue();
        }

        System.out.println("Total Inventory Value: " + total);
    }

    public static void main(String[] args) {

        while (true) {

            System.out.println("\n===== Inventory Management System =====");
            System.out.println("1. Add Product");
            System.out.println("2. View Products");
            System.out.println("3. Search Product");
            System.out.println("4. Update Quantity");
            System.out.println("5. Delete Product");
            System.out.println("6. Sort Products By Price");
            System.out.println("7. Show Total Inventory Value");
            System.out.println("8. Exit");

            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();

            switch (choice) {

                case 1:
                    addProduct();
                    break;

                case 2:
                    viewProducts();
                    break;

                case 3:
                    searchProduct();
                    break;

                case 4:
                    updateQuantity();
                    break;

                case 5:
                    deleteProduct();
                    break;

                case 6:
                    sortProductsByPrice();
                    break;

                case 7:
                    showTotalInventoryValue();
                    break;

                case 8:
                    System.out.println("Exiting program...");
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
