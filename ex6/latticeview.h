#include<iostream>
#include<fstream>

using namespace std;

void Print_lattice (int **vlat, const int &vlx, const int &vly, const int &vwidth, const int &vheight, const char* vfilename="output.ppm")
{
  int  i, j, k, l;
  int vw= vwidth/vlx, vh=vheight/vly;
  int r[5], g[5], b[5];

  r[0]= 255; g[0]= 255; b[0]= 255; //white
  r[1]=   0; g[1]= 255; b[1]=   0; //green
  r[2]= 255; g[2]=   0; b[2]=   0; //red
  r[3]=   0; g[3]=   0; b[3]=   0; //black
  r[4]=   0; g[4]=   0; b[4]= 255; //blue

  ofstream out (vfilename);

  out << "P3" << endl;
  out << vw*vlx << " " << vh*vly << endl;
  out << "255" << endl;

  for (i=vly-1; i>=0; i--)
    for (j=0; j<vh; j++)
      for (k=0; k<vlx; k++)
      {
        for (l=0; l<vw; l++)
        { out << r[vlat[i][k]] << " " << g[vlat[i][k]] << " " << b[vlat[i][k]] << " ";
        }
      } 
      out << endl;

  out.close ();
}
