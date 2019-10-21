#include<stdio.h>
#include<stdlib.h>

struct tlv_data{
	unsigned char type;
	unsigned int len;
	char data[0];
};

struct t1{
	int a;
	long b;
	char c[9];
//};
}__attribute__((__packed__));

static void test(struct tlv_data *a,struct tlv_data *b)
{
		struct t1 *tx;
		printf("a->type %d,a->len %d,a->data %s\n",a->type,a->len,a->data);
		tx = (struct t1 *)b->data;

		printf("tx->a %d ,tx->b %d ,tx->c %s\n",tx->a,tx->b,tx->c);

}
int main(int argc, char *argv[])
{
	struct tlv_data *d = malloc(sizeof(struct tlv_data)+5);
	struct tlv_data *b = malloc(sizeof(struct tlv_data) + sizeof(struct t1));
	struct t1 t1_1;
	d->type  = 2;
	d->len = 5;
	memcpy(d->data,"hello",5);

	b->type = 3;
	b->len = sizeof(struct t1);
	t1_1.a = 100;
	t1_1.b = 100000;
	bzero(t1_1.c,10);
	memcpy(t1_1.c,"Hello man",9);
	memcpy(b->data,&t1_1,sizeof(struct t1));
	test(d,b);
	void *a = &d->len;
	int num;
	memcpy(&num,a,sizeof(int));
	printf("%d\n",num);
	printf("the sizeof int %ld size of long %ld  size of t1 %ld \n",sizeof(int),sizeof(long),sizeof(struct t1));
}
