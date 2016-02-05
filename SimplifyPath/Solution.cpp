class Solution {
private:
    void pathToDirectories(stack<string> &directories, string &path) {
        string name;
        name.clear();
        path += '/';
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!name.empty()) {
                    if (name[0] == '.' && name.size() == 2 && name[1] == '.') {
                        if (!directories.empty()) {
                            directories.pop();
                        }
                    }
                    else if (!(name[0] == '.' && name.size() == 1)) {
                        directories.push(name);
                    }
                }
                name.clear();
            }
            else {
                name += path[i];
            }
        }
    }

    void directoriesToPath(string &answer, stack<string> &directories) {
        answer.clear();
        while (!directories.empty()) {
            answer = directories.top() + '/' + answer;
            directories.pop();
        }
        if (!answer.empty()) {
            answer = answer.substr(0, answer.size() - 1);
        }
        answer = '/' + answer;
    }

public:
    string simplifyPath(string path) {
        stack<string> directories;
        pathToDirectories(directories, path);
        string answer;
        directoriesToPath(answer, directories);
        return answer;
    }
};
