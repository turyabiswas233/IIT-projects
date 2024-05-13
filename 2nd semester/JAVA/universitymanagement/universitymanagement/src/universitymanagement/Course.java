package universitymanagement;

public class Course {
	private String courseName;
	private String courseID;
	private double numberOfCredits;

	public Course(String courseName, String courseID, double numberOfCredits) {
		super();
		this.courseName = courseName;
		this.courseID = courseID;
		this.numberOfCredits = numberOfCredits;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return courseName + " " + courseID + " " + numberOfCredits;
	}
}
