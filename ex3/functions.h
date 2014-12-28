void print(std::vector<int> grid,  const int n);
void hoshen_kopelman(std::vector<int>& grid, const int n, std::vector<int>& M);

bool left_empty(std::vector<int> grid, const int n, int index);
bool up_empty(std::vector<int> grid, const int n, int index);
bool left_occ(std::vector<int> grid, const int n, int index, int k);
bool up_occ(std::vector<int> grid, const int n, int index, int k);
