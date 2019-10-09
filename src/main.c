#include "mlx.h"

int main()
{
	void * mlx_ptr = mlx_init();
	void * win_ptr = mlx_new_window(mlx_ptr, 1024, 768, "my new window");
	win_ptr = 0;
	mlx_loop(mlx_ptr);
	return (0);
}