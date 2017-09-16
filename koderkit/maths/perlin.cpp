#include "perlin.hpp"
#include <math.h>
#include <cmath>

namespace kk3d {
	namespace math {
		PerlinGenerator::PerlinGenerator()
		{
			for(int i = 0; i < 3; i++)
			{
				this->_octave[i] = 4;
				this->_persist[i] = 1.0;
				this->_pressed[i] = false;
				this->_scale[i] = 1.0;
			}
		};
		
		void PerlinGenerator::set(int i, int o, double p, double f, bool pr)
		{
			this->_octave[i] = o;
			this->_persist[i] = p;
			this->_pressed[i] = pr;
			this->_scale[i] = f;
		};
		
		double PerlinGenerator::lerp(double a, double b, double u)
		{
			double ft = u * 3.141592;
			double f = (1.0 - cos(ft)) * 0.5;
			return a + (f + u) * 0.5 * (b - a);
		};
		
		double PerlinGenerator::fade(double t) {
			return t * t * t * (t * (t * 6 - 15) + 10);
		}
		
		double PerlinGenerator::grad(int hash, double x, double y, double z)
		{
			switch(hash & 0xF)
			{
				case 0x0: return  x + y;
				case 0x1: return -x + y;
				case 0x2: return  x - y;
				case 0x3: return -x - y;
				case 0x4: return  x + z;
				case 0x5: return -x + z;
				case 0x6: return  x - z;
				case 0x7: return -x - z;
				case 0x8: return  y + z;
				case 0x9: return -y + z;
				case 0xA: return  y - z;
				case 0xB: return -y - z;
				case 0xC: return  y + x;
				case 0xD: return -y + z;
				case 0xE: return  y - x;
				case 0xF: return -y - z;
				default: return 0;
			}
		}
		
		int PerlinGenerator::inc(int num, int repeat) {
			num++;
			if (repeat > 0) num %= repeat;
			return num;
		}
		
		double PerlinGenerator::perlin(double x, double y, double z, double repeat)
		{
			if(repeat > 0.0)
			{
				while(x > repeat) x -= repeat;
				while(y > repeat) y -= repeat;
				while(z > repeat) z -= repeat;
			}
			int xi = (int)x & 255;                              // Calculate the "unit cube" that the point asked will be located in
			int yi = (int)y & 255;                              // The left bound is ( |_x_|,|_y_|,|_z_| ) and the right bound is that
			int zi = (int)z & 255;                              // plus 1.  Next we calculate the location (from 0.0 to 1.0) in that cube.
			double xf = x-(int)x;
			double yf = y-(int)y;
			double zf = z-(int)z;

			double u = PerlinGenerator::fade(xf);
			double v = PerlinGenerator::fade(yf);
			double w = PerlinGenerator::fade(zf);

			int aaa, aba, aab, abb, baa, bba, bab, bbb;
			aaa = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[    xi ]+    yi ]+    zi ];
			aba = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[    xi ]+PerlinGenerator::inc(yi,repeat)]+    zi ];
			aab = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[    xi ]+    yi ]+PerlinGenerator::inc(zi,repeat)];
			abb = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[    xi ]+PerlinGenerator::inc(yi,repeat)]+PerlinGenerator::inc(zi,repeat)];
			baa = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[PerlinGenerator::inc(xi,repeat)]+    yi ]+    zi ];
			bba = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[PerlinGenerator::inc(xi,repeat)]+PerlinGenerator::inc(yi,repeat)]+    zi ];
			bab = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[PerlinGenerator::inc(xi,repeat)]+    yi ]+inc(zi,repeat)];
			bbb = PERLIN_PERM[PERLIN_PERM[PERLIN_PERM[PerlinGenerator::inc(xi,repeat)]+PerlinGenerator::inc(yi,repeat)]+PerlinGenerator::inc(zi,repeat)];

			double x1, x2, y1, y2;
			x1 = PerlinGenerator::lerp(PerlinGenerator::grad (aaa, xf  , yf  , zf),
					PerlinGenerator::grad (baa, xf-1, yf  , zf),
					u);
			x2 = PerlinGenerator::lerp(PerlinGenerator::grad (aba, xf  , yf-1, zf),
					PerlinGenerator::grad (bba, xf-1, yf-1, zf),
					u);
			y1 = PerlinGenerator::lerp(x1, x2, v);

			x1 = PerlinGenerator::lerp(PerlinGenerator::grad (aab, xf  , yf  , zf-1),
					  PerlinGenerator::grad (bab, xf-1, yf  , zf-1),
					  u);
			x2 = PerlinGenerator::lerp(PerlinGenerator::grad (abb, xf  , yf-1, zf-1),
   	               PerlinGenerator::grad (bbb, xf-1, yf-1, zf-1),
   	               u);
			y2 = PerlinGenerator::lerp(x1, x2, v);

			return (PerlinGenerator::lerp(y1, y2, w)+1)/2;
		}
		
		double PerlinGenerator::getPoint(double x, double y, double z)
		{
			double t = 0.0, d = 0.0;
			for(int i = 0; i < 3; i++)
			{
				t += this->perlinPoint(x,y,z,i) * this->_persist[i];
				d += this->_persist[i];
			}
			if(d > 0.0) return t / d;
			return 0.0;
		};
		
		double PerlinGenerator::perlinPoint(double x, double y, double z, int l)
		{
			double total = 0;
			double frequency = 1.0 / this->_scale[l];
			double amplitude = 1;
			double maxValue = 0;  // Used for normalizing result to 0.0 - 1.0
			for(int i = 0; i < this->_octave[l]; i++) {
				total += PerlinGenerator::perlin(x * frequency, y * frequency, z * frequency, 255.0) * amplitude;
				maxValue += amplitude;	
				amplitude *= this->_persist[l];
				frequency *= 2;
			}
			if(this->_pressed) return std::abs(((total/maxValue)*2.0) - 1.0);
    		return total/maxValue;
		};
	};
};

