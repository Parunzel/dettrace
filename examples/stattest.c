#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *f;
	FILE *v;

	system("touch examples/RICKROLLD; stat examples/RICKROLLD;");

	f = fopen("/home/christian/Masterthesis/dettrace/examples/RICKROLLD2", "w");
	system("stat examples/RICKROLLD2");
	fclose(f);

	v = fopen("/home/christian/Masterthesis/dettrace/examples/RICKROLLD3", "w");
	fclose(v);
	system("stat examples/RICKROLLD3");

	system("rm examples/RICKROLLD; rm examples/RICKROLLD2; rm examples/RICKROLLD3");
	return 0;
}

