#include<stdio.h>
#include<stdlib.h>
struct node
{
      int data;
      struct node *next;
};
typedef struct node list;
list* create_node();
list* insert(list *);
list* insertatbeg(list *);
list* insertatend(list *);
list* insertatpos(list *);
void traverse(list *);
int length(list *);
int search(list *);
void sort(list *);
list* reverse(list *);
list* delete(list *);
list* deleteatbeg(list *);
list* deleteatend(list *);
list* deleteatpos(list *);
int main()
{
     int s=1,len=0,flag=0;
     list *start = NULL;
     while(s!=0)
     {
          printf("\n\n			***********MENU***********\n1.Insertion\n2.Delete\n3.Length\n4.Search\n5.Sort\n6.Reverse\n7.Traverse\n0.Exit\nChoose the Operation: ");
          scanf("%d",&s);
          switch(s)
          {
               case 1:
               	       start = insert(start);
               	       break;
               case 2:
               	       start = delete(start);
               	       break;
               case 3:
                        len = length(start);
                        printf("\nThe Length of the Linked List is %d.\n",len);
                        break;
               case 4:
               		flag = search(start);
               		if(flag == 0)
               			printf("\nElement Not Found.\n");
			traverse(start);
               		break;
               case 5:
               		sort(start);
               		traverse(start);
               		break;
               case 6:
               		start = reverse(start);
               		traverse(start);
               		break;
               case 7:
                        traverse(start);
                        break;
               case 0:
                        printf("\n			***********EXIT***********\n");
                        break;
               default:
               	        printf("\nInvalid Choice.\n");
            }
     }
}
list* create_node()
{
     list* q;
     q=(list*)malloc(sizeof(list));
     if(q==NULL)
          printf("\nNode Not Created.\n");
     else
          printf("\nNode Created.\n");
     return(q);
}
list* insert(list* start)
{
	int c;
	if(length(start) == 0)
	{
		start = insertatbeg(start);
		traverse(start);
		return(start);		
	}
        printf("\n1.Insertion at Beginning.\n2.Insertion at End.\n3.Insertion at Position.\n4.Menu\n0.Exit\nChoose the Operation: ");
        scanf("%d",&c);
        switch(c)
        {
		case 1:
			start = insertatbeg(start);
 	                traverse(start);
 	                break;
                case 2:
			start = insertatend(start);
                        traverse(start);
                        break;
                case 3:
			start = insertatpos(start);
                        traverse(start);
                        break;
                case 4:
                        break;
                case 0:
                        printf("\n			*******EXIT*******\n");
                        exit(0);
                default:
                        printf("\nInvalid Choice.\n");
                        start=insert(start);
         }
         return(start);
}
list* insertatbeg(list* start)
{
 	int e;
	list* newnode;
	newnode = create_node();
	if(newnode == NULL)
		return(start);
        printf("\nEnter the value: ");
        scanf("%d",&e);
    	newnode->data = e;
    	if(start == NULL)
        	newnode->next = NULL;
    	else
        	newnode->next = start;
    	start = newnode;
    	return(start);
}
list* insertatend(list* start)
{
	int e;
	list *newnode,*temp;
	newnode = create_node();
	if(newnode == NULL)
    	    return(start);
	printf("\nEnter the Value: ");
	scanf("%d",&e);
	newnode->data = e;
	newnode->next = NULL;
 	if(start == NULL)
		start = newnode;
	else
	{
		temp = start;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
	return(start);
}
list* insertatpos(list *start)
{
   int i,pos,e;
   if(length(start) == 0)
   {
        start = insertatbeg(start);
        return(start);
   }
   printf("\nEnter the Position: ");
   scanf("%d",&pos);
   if(pos>length(start)+1)
   {
       printf("\nPosition not Found.\n");
       start = insertatpos(start);
   }
   else if(pos == 1)
   	start = insertatbeg(start);
   else
   {
	list* newnode,*temp=start;
   	newnode = create_node();
   	if(newnode == NULL)
       		return(start);
   	printf("\nEnter the Value: ");
  	scanf("%d",&e);
  	newnode->data = e;
   	for(i=1;i<pos-1;i++)
   		temp=temp->next;
   	newnode->next = temp->next;
 	temp->next=newnode;
   }
   return(start);
}

void traverse(list* start)
{
    list *temp=start;
    if(start == NULL)
    {
        printf("\nNo Element to print.\n");
        return;
    }
    printf("\nLinked List: ");
    while(temp!=NULL)
    {
    	printf(" %d[%lu] ",temp->data,(unsigned long)temp);
	temp = temp->next;
    }
}


int length(list* start)
{
    int len=0;
    list* temp=start;
    if(start == NULL)
        return(0);
    else
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
    }
    return(len);
}
list* delete(list *start)
{
	int c;
	if(length(start)==0)
	{
		printf("\nNo Element to Delete.\n");
		return(start);
	}
	else if(length(start)==1)
	{
		start = deleteatbeg(start);
		return(start);
	}
        printf("\n1.Deletion at Beginning.\n2.Deletion at End.\n3.Deletion at Position.\n4.Menu\n0.Exit\nChoose the Operation: ");
        scanf("%d",&c);
        switch(c)
        {
		case 1:
			start = deleteatbeg(start);
 	                traverse(start);
 	                break;
                case 2:
			start = deleteatend(start);
                        traverse(start);
                        break;
                case 3:
			start = deleteatpos(start);
                        traverse(start);
                        break;
                case 4:
                        break;
                case 0:
                        printf("\n			*******EXIT*******\n");
                        exit(0);
                default:
                        printf("\nInvalid Choice.\n");
                        start=delete(start);
         }
         return(start);
}
list* deleteatbeg(list *start)
{
	list* temp=start;
	temp=temp->next;
	free(start);
	start=temp;
	printf("\nElement Deleted.\n");
	return(start);
}
list* deleteatend(list *start)
{
	list* temp=start;
	while(temp->next->next!=NULL)
		temp=temp->next;
	free(temp->next);
	temp->next=NULL;
	printf("\nElement Deleted.\n");
	return(start);
}
list* deleteatpos(list *start)
{
	int pos,i;
	list *temp = start,*temp2;
	printf("\nEnter the Position to Delete: ");
	scanf("%d",&pos);
	if(pos>length(start))
	{
		printf("\nPlease a Valid Position.\n");
		start = deleteatpos(start);
	}
	else if(pos == 1)
		start = deleteatbeg(start);
	else if(pos == length(start))
		start = deleteatend(start);
	else
	{
		for(i=1;i<pos-1;i++)
			temp = temp->next;
		temp2 = temp->next;
		temp->next = temp->next->next;
		free(temp2);
		printf("\nElement Deleted.\n");
	}
	return(start);
}
int search(list *start)
{
	int key,flag=0;
	list* temp = start;
	if(length(start) == 0)
	{
		printf("\nNo Element to Search.\n");
		return(1);
	}
	printf("\nEnter the Element to Search: ");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(temp->data == key)
		{
			printf("\nElement Found.\n");
			flag=1;
			return(flag);
		}
		temp = temp->next;
	}
	return(flag);
}
void sort(list *start)
{
	int t;
	list *temp1,*temp2,*temp=start;
	for(temp1=start;temp1!=NULL;temp1=temp1->next)
	{
		for(temp2=start;temp2!=NULL;temp2=temp2->next)
		{
			if(temp1->data < temp2->data)
			{
				t=temp1->data;
				temp1->data = temp2->data;
				temp2->data = t;
			}
		}
	}
}

list* reverse(list *start)
{
	list *prev=NULL;
	list *current=start;
	list *next=NULL;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	start = prev;
	return(start);
}
