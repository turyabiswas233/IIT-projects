package universitymanagement;

public class User {
	private String username;
	private String name;
	private String password;
	private String email;

	public User(String username, String name, String password, String email) {
		this.username = username;
		this.name = name;
		this.password = password;
		this.email = email;
	}

	public boolean login(User user) {
		return user.username.equals(this.username) && user.password.equals(this.password);
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return username + " " + name + " " + password + " " + email;
	}
}
