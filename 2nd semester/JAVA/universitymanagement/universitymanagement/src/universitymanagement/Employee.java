package universitymanagement;

public class Employee extends User {
	private double salary;
	private String designation;
	private int startingYear;

	public Employee(String username, String name, String password, String email, double salary, String designation,
			int startingYear) {
		super(username, name, password, email);
		this.salary = salary;
		this.designation = designation;
		this.startingYear = startingYear;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public double getSalary() {
		return salary;
	}

	public void setDesignation(String designation) {
		this.designation = designation;
	}

	public String getDesignation() {
		return designation;
	}

}
