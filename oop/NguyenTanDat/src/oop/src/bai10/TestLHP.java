package bai10;

public class TestLHP {

	public static void main(String[] args) {
		SinhVien[] svs = new SinhVien[3];
		svs[0] = new SinhVien("123","Nguyen Van A");
		svs[1] = new SinhVien("456","Nguyen Van B");
		svs[2] = new SinhVien("789","Nguyen Van C");
		LopHocPhan lhp = new LopHocPhan("10", "OOP", "Nguyen Van D", "Thu 4, tiet 1-3, X11.04", svs);
		System.out.println(lhp);
	}
}
