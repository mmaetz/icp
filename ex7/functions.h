void initalize(std::vector< std::vector<char> >& cluster, const int seed, const double p);
int period(int index);
int energy_diff(std::vector< std::vector<char> >& cluster, int i, int j, int ferro);
void flip(std::vector< std::vector<char> >& cluster, int i, int j);
