#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Boock {
public:
	Boock() : page_read_use_(1001, 0) {};

	void ReadUsePage(int use_id, int page) {
		int page_lost = use_page_[use_id];
		if (page_lost == 0) {
			peaple_++;
		}
		use_page_[use_id] = page;
		for (int i = page_lost + 1; i <= page; i++) {
			page_read_use_[i]++;
		}

	}
	double CheerUse(int use_id) {
		if (use_page_[use_id] == 0) {
			return 0.0;
		}
		else if (peaple_ == 1) {
			return 1.0;
		}
		return  1.0 - static_cast<double>(page_read_use_[use_page_[use_id]] - 1) / (peaple_ - 1);
	}
private:

	unordered_map<int, int> use_page_;
	vector<int> page_read_use_;
	int peaple_ = 0;

};

void Read(istream& in, Boock& boock) {
	int val;
	in >> val;
	for (int i = 0; i < val; i++) {
		string command;
		in >> command;
		if (command == "READ") {
			int use_id, page;
			in >> use_id >> page;
			boock.ReadUsePage(use_id, page);
		}
		else if (command == "CHEER") {
			int use_id;
			in >> use_id;
			setprecision(6);
			cout << boock.CheerUse(use_id) << endl;
		}
		else {
			cout << "Error command";
		}
	}
}

int main() {
	Boock boock;
	Read(cin, boock);
}
