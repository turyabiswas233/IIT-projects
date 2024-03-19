 
import java.util.Scanner;

public class Main {
	static Product[] product = new Product[5]; 
	
	public static void copyArr(Product[] array,Product[] tmp) {
		for(int i=0;i<array.length;i++) {
			tmp[i] = array[i];
		}
	}
	
	public static void addItem(String name, int quantity,double price) {
		int length = getLen(product);
		if(product.length == length) {
			Product[] tempProducts = new Product[product.length+5];
			copyArr(product,tempProducts);
			tempProducts[length] = new Product(name,quantity,price,false);
			product = new Product[product.length+5];
			product = tempProducts;
		 }
		else {
			product[length] = new Product(name,quantity,price,false);
		}
	}
	public static int getLen(Product [] products) {
		int len = 0;
		for(Product product: products) {
			if(product!=null) len++;
		}
		return len;
	}
	
	public static void printArr() {
		for (Product p : product) {	
			//for each convert with class object
			if(p  == null) break;
			System.out.println( p); 
		}
	}
	
	public static void init() {
		Scanner inp = new Scanner(System.in);
		System.out.println("How many product?: ");
		int n = inp.nextInt();
		inp.nextLine();
		product = new Product[n];
		
		for (int i = 0; i < n; i++) { 
			System.out.println("Product name: ");
			String name = inp.nextLine();
			System.out.println("Product quantity: ");
			int quantity = Integer.parseInt(inp.nextLine());
			System.out.println("Product price: ");
			double price = Double.parseDouble(inp.nextLine());
			System.out.println("Product is availabe?: ");
			boolean isSale = inp.nextBoolean();
			inp.nextLine();
			product[i] = new Product(name,quantity,price,isSale);
		} 
	}
	public static void main(String[] args) { 
		init();
		addItem("orange", 3, 10);
		printArr();
		
		
	}

}
	
