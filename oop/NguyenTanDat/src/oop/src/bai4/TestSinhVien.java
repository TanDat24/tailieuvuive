package bai4;

public class TestSinhVien {

	public static void main(String[] args) throws Exception {
		try {
			DiemSinhVien sv1 = new DiemSinhVien(22675131,"Nguyen Tan Dat",10,10);
			System.out.println(sv1);
			DiemSinhVien sv2 = new DiemSinhVien(1111,"hihi",7,8);
			System.out.println(sv2);
		} catch(Exception e) {
			e.printStackTrace();
		}
	}

}
