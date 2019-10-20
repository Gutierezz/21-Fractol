#include "fractol.h"

t_colp		color_init(double iter, t_complex last_z, double smooth)
{
	t_colp colp;

	colp.iter = iter;
	colp.z = last_z;
	colp.smooth = smooth;
	return (colp);
}

static int color_func(double i,double f, double p)
{
    return ((int)pow(255*(cos(sqrt(i) * f + p)), 2.0));
}
// color |= (UCHAR)(9 * (1 - perc) * pow(perc, 3) * 255) << 16;
		// color |= (UCHAR)(15 * pow((1 - perc),2) * pow(perc, 2) * 255) << 8;
		// color |= (UCHAR)(8.5 * pow((1 - perc), 3)  * perc * 255);

t_color		get_color(t_colp colp, t_fract *fract)
{
	double	perc;
	t_color ucol;

	perc = 0.0;
	ucol.color = 0;
	if ((int)colp.iter >= fract->max_iter)
		return (inside_coloring(colp, fract));
	if (fract->color_mode == 1)
	{
		perc = colp.iter;
		ucol.ch[fract->c1] = (UCHAR)(255 - perc * 5.1);
		ucol.ch[fract->c2] = (UCHAR)(perc * 25) % 255;
		ucol.ch[fract->c3] = (UCHAR)(255 - perc * 3.5);
	}
	else if (fract->color_mode == 2)
	{
		perc = colp.iter + atan(colp.z.im/colp.z.re);
		ucol.ch[fract->c1] = (UCHAR)(0.8 * sin(perc) * 150 + 65);
		ucol.ch[fract->c2] = (UCHAR)(0.6 * sin(perc) * 150 + 65);
		ucol.ch[fract->c3] = (UCHAR)(0.2 * sin(perc) * 150 + 15);
	}
	else if (fract->color_mode == 3)
	{
		perc = colp.iter / fract->max_iter;
		ucol.ch[fract->c1] = (UCHAR)(color_func(perc, 1, 0));
		ucol.ch[fract->c2] = (UCHAR)(color_func(perc, 1, 120));
		ucol.ch[fract->c3] = (UCHAR)(color_func(perc, 1, 240));
	}
	else if (fract->color_mode == 4)
	{
		perc = (colp.iter + colp.z.re + colp.z.im)/ fract->max_iter;
		ucol.ch[fract->c3] = (UCHAR)(7.4 * pow(1.0 - perc, 2) * 255);
		ucol.ch[fract->c2] = (UCHAR)(5.7 * (1.0 - pow(perc, 1) * 255));
		ucol.ch[fract->c1] = (UCHAR)(4.3 * pow(perc, 3) * 255);
	}
	return (ucol);
}


t_color		inside_coloring(t_colp colp, t_fract *fract)
{
	int perc;
	t_color ucol;

	perc = colp.iter;
	ucol.color = 0;
	if (fract->inside_mode == 0)
		return (ucol);
	else if (fract->inside_mode == 1)
	{
		perc = colp.iter + colp.z.im / colp.z.re;
		ucol.ch[0] = (UCHAR)(perc * 3.9) % 255;
		ucol.ch[1] = (UCHAR)(255 - perc * 5.5);
		ucol.ch[2] = (UCHAR)(255 - perc * 8.5);
	}
	return (ucol);
}
