package universitymanagement;

import java.util.ArrayList;

public class Student extends User {
	private ArrayList<Course> courses;
	private int year;
	private int semester;

	public Student(String username, String name, String password, String email, int year, int semester) {
		super(username, name, password, email);
		this.year = year;
		this.semester = semester;
		this.courses = new ArrayList<>();
	}

	public void addCourse(Course course) {
		courses.add(course);
	}

	public void dropCourse(Course course) {
		courses.remove(course);
	}

	public void setYear(int year) {
		this.year = year;
	}

	public void setSemester(int semester) {
		this.semester = semester;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		StringBuffer stringBuffer = new StringBuffer();
		stringBuffer.append(super.toString() + " ");
		stringBuffer.append(year+" ");
		stringBuffer.append(semester+" ");

		for (Course course : courses) {
			stringBuffer.append(course.toString() + " ");
		}
		return stringBuffer.toString().trim();
	}
}
