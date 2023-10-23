// C++ implementation of the above approach
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

// Số thành phố trong TSP
#define V 5

// Tên các thành phố
#define GENES ABCDE

// Giá trị nút bắt đầu
#define START 0

// Kích thước dân số ban đầu cho thuật toán
#define kich_thuoc_ban_dau 10

// Cấu trúc của một GNOME chuỗi xác định đường đi qua bởi người bán hàng trong khi giá trị thể dục của đường dẫn được lưu trữ trong một số nguyên

struct individual {
	string gnome;
	int do_thich_nghi;
};

// Hàm trả về một số ngẫu nhiên
// từ đầu và cuối
int rand_num(int start, int end)
{
	int r = end - start;
	int rnum = start + rand() % r;
	return rnum;
}

//Hàm kiểm tra ký tự
// đã xảy ra trong chuỗi
bool check_lap(string s, char ch)
{
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ch)
			return true;
	}
	return false;
}

// Hàm trả về một GNOME bị đột biến
// Gnome bị đột biến là một chuỗi
// với một trao đổi ngẫu nhiên
// của 2 gen để tạo ra nguồn biến dị trong loài
string mutatedGene(string gnome)
{
	while (true) {
		int r = rand_num(1, V);
		int r1 = rand_num(1, V);
		if (r1 != r) {
			char temp = gnome[r];
			gnome[r] = gnome[r1];
			gnome[r1] = temp;
			break;
		}
	}
	return gnome;
}

// Hàm trả về chuỗi GNOME hợp lệ cần thiết để tạo quần thể
string create_gnome()
{
	string gnome = "0";
	while (true) {
		if (gnome.size() == V) {
			gnome += gnome[0];
			break;
		}
		int temp = rand_num(1, V);
		if (!check_lap(gnome, (char)(temp + 48)))
			gnome += (char)(temp + 48);
	}
	return gnome;
}

// Hàm trả về giá trị phù hợp của gnome.
// Giá trị phù hợp là độ dài đường dẫn
// của đường dẫn được đại diện bởi Gnome.
int tinh_do_thich_nghi(string gnome)
{
	int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },
					  { 2, 0, 4, 8, INT_MAX },
					  { INT_MAX, 4, 0, 3, 3 },
					  { 12, 8, 3, 0, 10 },
					{ 5, INT_MAX, 3, 10, 0 } };
	int f = 0;
	for (int i = 0; i < gnome.size() - 1; i++) {
		if (map[gnome[i] - 48][gnome[i + 1] - 48] == INT_MAX)
			return INT_MAX;
		f += map[gnome[i] - 48][gnome[i + 1] - 48];
	}
	return f;
}

//Hàm trả về giá trị đã cập nhật
// của phần tử làm mát.
int cooldown(int temp)
{
	return (90 * temp) / 100;
}

// Bộ so sánh cho cấu trúc GNOME.
bool lessthan(struct individual t1,
			struct individual t2)
{
	return t1.do_thich_nghi < t2.do_thich_nghi;
}

// Hàm tiện ích cho bài toán TSP.
void TSPUtil(int map[V][V])
{
	// Số thế hệ
	int gen = 1;
	// Số lần lặp gen
	int gen_thres = 5;

	vector<struct individual> population;
	struct individual temp;

	// Tạo nhóm GNOME.
	for (int i = 0; i < kich_thuoc_ban_dau; i++) {
		temp.gnome = create_gnome();
		temp.do_thich_nghi = tinh_do_thich_nghi(temp.gnome);
		population.push_back(temp);
	}

	cout << "\nquan the ban dau: " << endl
		<< "GONE    gia tri thich nghi cua gen \n";
	for (int i = 0; i < kich_thuoc_ban_dau; i++)
		cout << population[i].gnome << " "
			<< population[i].do_thich_nghi << endl;
	cout << "\n";

	bool found = false;
	int temperature = 10000;

    // Lặp lại để thực hiện
    // lai quần thể và đột biến gen.
	while (temperature > 1000 && gen <= gen_thres) {
		sort(population.begin(), population.end(), lessthan);
		cout << "\nCurrent temp: " << temperature << "\n";
		vector<struct individual> new_population;

		for (int i = 0; i < kich_thuoc_ban_dau; i++) {
			struct individual p1 = population[i];

			while (true) {
				string new_g = mutatedGene(p1.gnome);
				struct individual new_gnome;
				new_gnome.gnome = new_g;
				new_gnome.do_thich_nghi = tinh_do_thich_nghi(new_gnome.gnome);

				if (new_gnome.do_thich_nghi <= population[i].do_thich_nghi) {
					new_population.push_back(new_gnome);
					break;
				}
				else {

					// Chấp nhận những đứa trẻ bị từ chối tại
                    // một xác suất có thể trên ngưỡng.
					float prob = pow(2.7,-1 * ((float)(new_gnome.do_thich_nghi - population[i].do_thich_nghi) / temperature));
					if (prob > 0.5) {
						new_population.push_back(new_gnome);
						break;
					}
				}
			}
		}

		temperature = cooldown(temperature);
		population = new_population;
		cout << "the he " << gen << " \n";
		cout << "GONE   gia tri thich nghi cua gen\n";

		for (int i = 0; i < kich_thuoc_ban_dau; i++)
			cout << population[i].gnome << " "
				<< population[i].do_thich_nghi << endl;
		gen++;
	}
}

int main()
{

	int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },
					{ 2, 0, 4, 8, INT_MAX },
					{ INT_MAX, 4, 0, 3, 3 },
					{ 12, 8, 3, 0, 10 },
					{ 5, INT_MAX, 3, 10, 0 } };
	TSPUtil(map);
}
