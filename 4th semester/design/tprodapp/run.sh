#!/bin/bash
# filepath: /home/tb07/Documents/design_patter/tprodapp/run.sh

set -e  # Exit on error

echo "=== JavaFX Application Setup and Runner ==="

# # Check if Maven is installed
 if ! command -v mvn &> /dev/null; then
     echo "Maven is not installed. Installing Maven..."
     sudo apt update
     sudo apt install maven -y
     echo "Maven installed successfully."
 fi

# # Check if SQLite is installed
 if ! command -v sqlite3 &> /dev/null; then
     echo "SQLite3 is not installed. Installing SQLite3..."
     sudo apt update
     sudo apt install sqlite3 -y
     echo "SQLite3 installed successfully."
 fi

# # Create database if it doesn't exist
# if [ ! -f "data.db" ]; then
#     echo "Creating database from data.sql..."
#     sqlite3 data.db < data.sql
#     echo "Database created successfully."
# else
#     echo "Database already exists."
# fi

# Check if JavaFX is available via Maven (recommended approach)
echo "Building and running the project using Maven..."
mvn clean compile

# Try to run with Maven JavaFX plugin first (recommended)
if mvn javafx:run 2>/dev/null; then
    echo "Application started successfully with Maven!"
    exit 0
fi

echo "Maven JavaFX plugin failed. Trying direct Java execution..."

# Alternative: Install OpenJFX if not available
echo "Installing OpenJFX..."
sudo apt update
sudo apt install openjfx -y

# Try to find JavaFX installation
JAVAFX_PATHS=(
    "/usr/share/openjfx/lib"
    "/usr/lib/jvm/javafx-sdk/lib"
    "/opt/javafx/lib"
    "/usr/lib/x86_64-linux-gnu/openjfx/lib"
)

JAVAFX_PATH=""
for path in "${JAVAFX_PATHS[@]}"; do
    if [ -d "$path" ] && [ -f "$path/javafx.controls.jar" ]; then
        JAVAFX_PATH="$path"
        echo "Found JavaFX at: $JAVAFX_PATH"
        break
    fi
done

if [ -z "$JAVAFX_PATH" ]; then
    echo "Error: JavaFX not found. Please install JavaFX SDK manually."
    echo "You can download it from: https://openjfx.io/"
    exit 1
fi

# Run the application with direct Java command
echo "Running JavaFX application with Java..."
java --module-path "$JAVAFX_PATH"  --add-modules javafx.controls,javafx.fxml,javafx.graphics --add-opens javafx.fxml/javafx.fxml=ALL-UNNAMED -cp "target/classes:target/dependency/*" com.example.App
