extern void $Super$$func1(void);
extern void $Super$$func2(void);

extern void load_overlay(int n);

void $Sub$$func1(void)
{
	load_overlay(1);
	$Super$$func1();
}

void $Sub$$func2(void)
{
	load_overlay(2);
	$Super$$func2();
}