package bai5;

public class HinhTamGiac {
	private double ma;
	private double mb;
	private double mc;
	public HinhTamGiac() {
		super();
	}
	public HinhTamGiac(double ma, double mb, double mc) {
		if (ma <= 0 || mb <= 0 || mc <= 0 || ma + mb <= mc || ma + mc <= mb || mb + mc <= ma) {
			this.ma = this.mb = this.mc = 0;
        } else {
		this.ma = ma;
		this.mb = mb;
		this.mc = mc;
        }
	}
	public double getMa() {
		return ma;
	}
	public void setMa(double ma) {
		if(ma > 0 && ma + this.mb > this.mc && ma + this.mc > this.ma) {
			this.ma = ma;
		}
	}
	public double getMb() {
		return mb;
	}
	public void setMb(double mb) {
		if (mb > 0 && mb + this.ma > this.mc && mb + this.mc > this.ma) {
            this.mb = mb;
        }
	}
	public double getMc() {
		return mc;
	}
	public void setMc(double mc) {
		if (mc > 0 && mc + this.ma > this.mb && mc + this.mb > this.ma) {
            this.mc = mc;
        }
	}
	public double tinhChuVi() {
        return this.ma + this.mb + this.mc;
    }
	public double tinhDienTich() {
        double s = tinhChuVi() / 2;
        return Math.sqrt(s * (s - this.ma) * (s - this.mb) * (s - this.mc));
    }
	public String kieuTamGiac() {
        if (this.ma == this.mb && this.ma == this.mc) {
            return "đều";
        } else if (this.ma == this.mb || this.ma == this.mc || this.mb == this.mc) {
            return "cân";
        } else if (this.ma * this.ma == this.mb * this.mb + this.mc * this.mc || this.mb * this.mb == this.ma *this.ma + this.mc * this.mc || this.mc * this.mc == this.ma * this.ma + this.mb * this.mb) {
            return "vuông";
        } else {
            return "thường";
        }
    }
	@Override
    public String toString() {
        return "Cac canh cua tam giac: ma = " + this.ma + ", mb = " + this.mb + ", mc = " + this.mc +
               "\nKieu tam giac: " + kieuTamGiac() +
               "\nChu vi: " + tinhChuVi() +
               "\nDien tich: " + tinhDienTich();
    }
}
