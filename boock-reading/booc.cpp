#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Book {
public:
	Book() : page_read_use_(1001, 0) {};
		
	void Read(istream& in) {
		int val;
		in >> val;
		for (int i = 0; i < val; i++) {
			string command;
			in >> command;
			if (command == "READ") {
				int use_id, page;
				in >> use_id >> page;
				ReadUsePage(use_id, page);
			}
			else if (command == "CHEER") {
				int use_id;
				in >> use_id;
				CheerUse(use_id);
			}
			else {
				cout << "Error command";
			}
		}
	}
private:
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
	void CheerUse(int use_id) {
		if (use_page_[use_id] == 0) {
			cout << 0 << endl;
		}
		else if (peaple_ == 1) {
			cout << 1 << endl;
		}
		else {
			cout << setprecision(6) << 1.0 - static_cast<double>(page_read_use_[use_page_[use_id]] - 1) / (peaple_ - 1) << endl;
		}
	}
	unordered_map<int,int> use_page_;
	vector<int> page_read_use_;
	int peaple_ = 0;

};


int main() {
	Book book;
	book.Read(cin);
}
