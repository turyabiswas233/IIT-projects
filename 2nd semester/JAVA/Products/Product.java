package pkg;

class Product {
	private String name;
	private int quantity;
	private double price; 
	private boolean onSale;
	
	public Product() { 
	}
	
	public Product( String name, int quantity, double price, boolean onSale) {
		this.name = name;
		this.quantity  = quantity;
		this.price = price; 
		this.onSale = onSale;
	}
	
	public String getName() {
		return name;
	}
	public int getQuantity() {
		return quantity;
	}
	public double getPrice() {
		return price;
	}
	public boolean getIsOnSale() {
		return onSale;
	}
	 
	public void setName (String name) {
		this.name = name;
	}

	public void setQuantity(int quantity) {
		this.quantity= quantity;
	}
	public void setPrice(double price) {
		this.price= price;
	}
	public void setIsOnSale(boolean onSale) {
		this.onSale= onSale;
	} 
	
	@Override
	public String toString() {
		return ""+name+": "+quantity+", $"+price+", Total: $"+(quantity*price) +"{ "+(onSale ? "availabe" : "sold out") +" }";
	}
	
}
 








