package universitymanagement;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Course courseOOP = new Course("OOP", "SE 101", 3);
		Course courseMath = new Course("MATH", "MATH 102", 3);
		Course courseStat = new Course("STAT", "STAT 103", 3);

		Student jack = new Student("jack11", "Jack", "1111", "jack@gmail.com", 1, 2);
		Student hasan = new Student("hasan", "Hasan", "1112", "hasan@gmail.com", 2, 2);

		Teacher Hayley = new Teacher("h112", "Hayley", "222", "h@gmail.com", 50000, "Lecturer", 2019);

		Staff Matt = new Staff("matt", "Matt", "111", "matt@gmail.com", 40000, "Senior Officer", 2019);
		Staff Karim = new Staff("kar", "Karim", "1122", "karim@gmail.com", 30000, "Office Staff", 2020);

		System.out.println(jack.login(hasan));
		jack.addCourse(courseOOP);
		hasan.addCourse(courseMath);
		hasan.addCourse(courseStat);
		System.out.println(jack);
		System.out.println(hasan);

		Hayley.setSalary(100);

		Matt.setSalary(100);

		Karim.setSalary(100);

		System.out.println(Hayley.getSalary() + " " + Matt.getSalary() + " " + Karim.getSalary());

	}

}
