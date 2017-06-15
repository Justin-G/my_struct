#include <stdio.h>
#include <stdlib.h>
typedef struct i_list_s i_list_t;

struct i_list_s
{
	int i_data;
	int num;
	i_list_t *next;
};

i_list_t* i_list_init(void)
{
	
	i_list_t *h;

	
	h = (i_list_t*)malloc(sizeof(i_list_t));
	if(h == NULL)
	{
		return h;
	}
	
	h->next = NULL;
	h->num = 0;
	h->i_data= -1;
	return h;
}

void foreach_i_list(i_list_t* t_i_list)
{
	i_list_t * n;
	if(t_i_list == NULL || t_i_list->num == 0 || t_i_list->next == NULL)
	{
		printf("Empty");
	}else
	{
		n = t_i_list;
		while(n)
		{
			printf("%2d %2d %2d %2d\n",n->num, n->i_data,(int)n,(int)n->next);
			n=n->next;
		}
		
	}
}

void i_list_destroy(i_list_t* t_i_list)
{
	i_list_t *n,*p;
	int i=0;
	if(t_i_list != NULL)
	{
		
		p = t_i_list;
		n = t_i_list->next;
		while(p != NULL)
		{
			
			free(p);
			p = n;
			if(n != NULL)
				n = n->next;
			i++;
			
		}
	}else
	{
		printf("Empty");
	}
	printf("DONE\n");
}

int i_list_creator(i_list_t *t_i_list,int num)
{
	i_list_t *tmp,*p;
	int i = 0,t_data=0;;
	if(t_i_list == NULL)
	{
		printf("ERROR\n");
		return -1;
	}
	
	p = t_i_list;
	p->num = num;
	for(i;i < num; i++)
	{
		t_data = rand() % 100 + 1;
		tmp = (i_list_t*)malloc(sizeof(i_list_t));
		tmp->next = NULL;
		tmp->i_data = t_data;
		tmp->num = 0;
		p->next = tmp;
		p = tmp;
	}
	return i;
	
	
}

int i_list_delete(i_list_t *t_i_list,int num)
{
	i_list_t *p,*r,*n;
	int t_n=0,tmp = 0;
	if(t_i_list == NULL || t_i_list->num < num)
	{
		printf("ERROR");
		return -1;
	}
	p = r = t_i_list;
	n = t_i_list->next;
	for(t_n;t_n < num ;t_n++)
	{
		p = r;
		r = n;

		if(n != NULL)
			n = n->next;
	}
	
	p->next = n;
	tmp = r->i_data;
	free(r);
	t_i_list->num -=1;
	return tmp;	
}

int i_list_insert(i_list_t *t_i_list, int num)
{
	i_list_t *tmp,*p;
	int i = 0;
	if(t_i_list == NULL )
	{
		printf("ERROR");
		return -1;
	}
	
	p = t_i_list;
	for(i;i < num; i++)
	{
		p = p->next;
		
	}
	tmp = (i_list_t*)malloc(sizeof(i_list_t));
	//i = rand()%100+1;
	//printf("%d\n",i);
	tmp->i_data = rand()%100+1;
	tmp->num = 0;
	
	tmp->next = p->next;
	p->next = tmp;
	t_i_list->num +=1;
	return num;
	
}



int main(void)
{
	int n;
	i_list_t* my_list;
	my_list = i_list_init();
	if(my_list == NULL)
	{
		printf("ERROR");
	}
	n = i_list_creator(my_list,5);
	printf("创建了%d个元素的链表\n",n);
	
	foreach_i_list(my_list);
	n = i_list_delete(my_list,3);
	printf("删除了%d的元素\n",n);
	foreach_i_list(my_list);
	n = i_list_insert(my_list,2);
	printf("元素插入到第%d\n",n);
	foreach_i_list(my_list);
	
	i_list_destroy(my_list);
	return 0;
}