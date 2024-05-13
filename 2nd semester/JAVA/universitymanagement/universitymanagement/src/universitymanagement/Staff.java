package universitymanagement;

public class Staff extends Employee {

	public Staff(String username, String name, String password, String email, double salary, String designation,
			int startingYear) {
		super(username, name, password, email, salary, designation, startingYear);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void setSalary(double baseAmount) {
		// TODO Auto-generated method stub
		if (this.getDesignation().endsWith("Officer")) {
			super.setSalary(super.getSalary() + baseAmount * 0.25);
		} else {
			super.setSalary(super.getSalary() + baseAmount * 0.10);
		}
	}
}
