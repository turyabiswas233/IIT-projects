package universitymanagement;

import java.util.ArrayList;

public class Teacher extends Employee {
	private ArrayList<Course> listOfCourses;

	public Teacher(String username, String name, String password, String email, double salary, String designation,
			int startingYear) {
		super(username, name, password, email, salary, designation, startingYear);
		listOfCourses = new ArrayList<>();
	}

	public void addCourse(Course course) {
		listOfCourses.add(course);
	}

	@Override
	public void setSalary(double baseAmount) {
		// TODO Auto-generated method stub
		super.setSalary(super.getSalary() + baseAmount * 0.25);
	}
}
