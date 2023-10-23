package bai5;

public class TestHinhTamGiac {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HinhTamGiac[] TamGiac = new HinhTamGiac[5];


		TamGiac[0] = new HinhTamGiac(1, 1, 3); 
		TamGiac[1] = new HinhTamGiac(-2, 4, 5); 
		TamGiac[2] = new HinhTamGiac(3, 4, 5);
        TamGiac[3] = new HinhTamGiac(2, 2, 3);
        TamGiac[4] = new HinhTamGiac(4, 4, 4); 

       //TamGiac[2].setMa(6);
        
        for (int i = 0; i < TamGiac.length; i++) {
            System.out.printf("%-10d %-10s %-10.2f %-10.2f %-10.2f\n",
                    (i + 1),
                    TamGiac[i].kieuTamGiac(),
                    TamGiac[i].getMa(),
                    TamGiac[i].getMb(),
                    TamGiac[i].getMc());
        }
	}

}
