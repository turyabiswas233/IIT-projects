# Instructions
##NB: use **VSCODE** to run `App.java` file. Sometimes my projects does not work in `Intellij IDEA`
## Installing Java
1. Ensure you have Java installed:
    ```bash
    java -version
    ```
    If not installed, download and install Java from [Oracle](https://www.oracle.com/java/) or use your package manager.

2. Install:
    - On Ubuntu/Debian:
      ```bash
      sudo apt update
      sudo apt install openjdk-24-jdk
      ```
    - On Windows, download the installer from [Maven's official site](https://maven.apache.org/).

3. Verify installation:
    ```bash
    mvn -version
    ```

## Converting `data.sql` to `data.db` with SQLite3
1. Ensure SQLite3 is installed:
    ```bash
    sqlite3 --version
    ```
    If not installed, install SQLite3 using your package manager.

2. Convert `data.sql` to `data.db`:
    ```bash
    sqlite3 data.db < data.sql
    ```

3. Verify the database:
    ```bash
    sqlite3 data.db
    ```
    Inside the SQLite shell, you can run:
    ```sql
    .tables
    ```
    to check the tables in the database.
