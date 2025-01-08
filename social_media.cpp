#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
public:
    string username;
    vector<string> posts;

    User(string user) {
        username = user;
    }

    void createPost() {
        string post;
        cout << "Enter your post: ";
        cin.ignore();
        getline(cin, post);
        posts.push_back(post);
        cout << "Post added successfully!\n";
    }

    void viewPosts() {
        cout << "Posts by " << username << ":\n";
        for (int i = 0; i < posts.size(); i++) {
            cout << i + 1 << ". " << posts[i] << endl;
        }
    }
};

class SocialMedia {
private:
    vector<User> users;

public:
    void registerUser() {
        string username;
        cout << "Enter username: ";
        cin >> username;
        users.push_back(User(username));
        cout << "User registered successfully!\n";
    }

    User* getUser(string username) {
        for (auto &user : users) {
            if (user.username == username) {
                return &user;
            }
        }
        return nullptr;
    }
};

int main() {
    SocialMedia platform;
    int choice;
    string username;
    User* user = nullptr;  // Declare user pointer outside the loop

    while (true) {
        cout << "\n1. Register\n2. Log In\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            platform.registerUser();
            break;

        case 2:
            cout << "Enter username to log in: ";
            cin >> username;
            user = platform.getUser(username);
            if (user != nullptr) {
                int userChoice;
                // Inner loop for logged-in user
                while (true) {
                    cout << "\n1. Create Post\n2. View Posts\n3. Log Out\nEnter your choice: ";
                    cin >> userChoice;

                    switch (userChoice) {
                    case 1:
                        user->createPost();
                        break;
                    case 2:
                        user->viewPosts();
                        break;
                    case 3:
                        cout << "Logged out successfully!\n";
                        user = nullptr; // Reset user to nullptr after logging out
                        break;
                    default:
                        cout << "Invalid choice, try again.\n";
                    }

                    if (user == nullptr) {
                        break;  // Exit the inner loop if the user logs out
                    }
                }
            } else {
                cout << "User not found!\n";
            }
            break;

        case 3:
            cout << "Exiting... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
