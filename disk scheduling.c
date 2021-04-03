# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define PI 3.14
double seek_queue=0.0,seek_stack=0.0;

//Queue using linked list
struct queue
{
    
    int data;
    struct queue *next;
}*front=NULL,*rear=NULL;

//stack using linked list
struct stack
{
    int data;
    struct stack *next;
    
}*top=NULL;

double seek_time_calculator(int x1,int x2)
{
    double t1,t2,t3,t4,ans;
    t1=exp(sin(pow(x1,3)))+exp(cos(pow(x2,2)));
    t2=pow(PI,3)*sqrt(pow(sin(x2),2)+pow(cos(x1),2));
    t3=888.444*exp(sin(x1-x2));
    t4=exp(sin(x1-x2)+cos(x1+x2));
    ans=((t1/t2)*(t3))/t4;
    return(ans);
    
}
//i/o requests to queue for fcfs
void enqueue(int E)
{
    struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
    temp->data=E;
    temp->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        
        rear->next=temp;
        rear=rear->next;
    }
    printf("\nRequest for I/O to block on cylinder %d has been successfully enqueued to the disk queue\n",rear->data);
    
}
//FCFS SCHEDULING
void FCFS()
{
    double seek;
    struct queue *i;
    i=front;
    if(i!=NULL)
    {
        while(i->next!=NULL)
        {
            seek=seek_time_calculator(i->data,i->next->data);
            seek_queue+=seek;//seek time
            printf("\nDisk head moves from %d to %d with seek time=%lf",i->data,i->next->data, seek);
            i=i->next;
            
        }
    
        
    }  
    else
    {
        printf("\nSorry,wrong order...Do:1.Read,2.FCFS Scheduling,3.Display");
    }
}
//I/O Requests cleared.As they are cleared,they are deleted from memory.
void dequeue()
{
    struct queue *i;
    if(front==NULL && rear==NULL)
    {
        printf("\nUnderflow error");
    }
    else
    {
        printf("\nDisk head done moving to the request for I/O to block on cylinder:%d\n",front->data);
        if(front!=rear)
        {
            i=front;
            front=front->next;
            free(i);
        }
        else
        {
            front=NULL;
            rear=NULL;
        }
    }
}
void display_FCFS()
{
    int size=0;
    double avg;
    struct queue *i;
    i=front;
    if(i!=NULL)
    {
        i=front->next;   //first ele=head
        while(i!=NULL)
        {
            size++;
            i=i->next;
        }
        avg=seek_queue/(float)size;
        printf("\nSeek time=%lf",seek_queue);
        printf("\nAvg time=%lf",avg);
        printf("\nDisk head done moving in the order of the disk queue:\n");
        i=front;
        while(i!=NULL)
        {
            printf("%d:\n",i->data);
            dequeue();
            i=i->next;
        }
        seek_queue=0;
        
    }
    else
    {
        printf("\nSorry,wrong order...Do:1.Read,2.FCFS Scheduling,3.Display");  
    }
}
//pushing requests to stack
void push(int E)
{
    struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=E;
    
    if(top==NULL)
    {
        temp->next=NULL;
      
    }
    else
    {
        temp->next=top;
    }
    top=temp;
    printf("\n%d has been successfully pushed to disk stack",top->data);
    
}
void pop()
{
    struct stack *i;
    
    if(top==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        i=top;
        top=top->next;
        printf("\nDisk head done moving to the request for I/O to the block on cylinder:%d\n",i->data);
        free(i);
    }
}
//FCLS Scheduling
void FCLS() //request clearing...
{
    double seek;
    struct stack *i;
    i=top;
    if(i!=NULL)
    {
        while(i->next!=NULL)
        {
            seek=seek_time_calculator(i->data,i->next->data);
            seek_stack+=seek;//seek time
            printf("\nDisk head moves from %d to %d with seek time=%lf",i->data,i->next->data,seek);
            i=i->next;
            
        }
    
        
    }  
    else
    {
        printf("\nSorry,wrong order...Do:1.Read,2.FCLS Scheduling,3.Display");
    }
}
void display_FCLS()
{
    int size=0;
    double avg;
    struct stack *i;
    i=top;
    if(i!=NULL)
    {
        i=top->next;
        //first ele=head at head
        while(i!=NULL)
        {
            size++;
            i=i->next;
        }
        printf("\nDisk head moved in the order of the disk stack:\n");
        i=top;
        while(i!=NULL)
        {
            printf("\n%d:\n",i->data);
            pop();
            i=i->next;
        }
        avg=seek_stack/(float)size;
        printf("\nSeek time=%lf",seek_stack);
        printf("\nAvg time=%lf",avg);
        seek_stack=0;
        
    }
    else
    {
        printf("\nSorry,wrong order...Do:1.Read,2.FCLS Scheduling,3.Display");  
    } 
}
void main()
{
    int n1,n2,status_FCFS=1,status_whole=1,status_FCLS=1;
    int ele2,ch1,ch2,ch3,ele1,head1,head2;
    
    printf("\n************************DSA MINIPROJECT****************************\n");
    printf("\n-----------DATA STRUCTURE USED:STACK AND QUEUE USING LINKED LIST-------\n");
    printf("\n#APPLICATION:First Come First Serve(FCFS) disk scheduling using queue and FIrst Come Last Serve(FCLS) disk scheduling using stack\n");
    
    while(status_whole==1)
    {
        printf("\nHow do you want to disk schedule-\n1.First Come First Serve(FCFS) disk scheduling using queue,\n2.FIrst Come Last Serve(FCLS) disk scheduling using stack,\n3.EXIT");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
            {
                 while(status_FCFS==1)
                 {
                    printf("\nFCFS Disk scheduling is done in the following order:\n1.Input cylinders\n2.Disk scheduling\n3.View seek time taken for the disk scheduling\nWhat do you want to do-\n1.Input cylinders,\n2.Do the FCFS Scheduling,\n3.Display,\n4.Exit");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1:
                        {
                            
                            printf("\nEnter the size of queue request:");
                            scanf("%d",&n1);
                            printf("\nEnter the initial head position:");
                            scanf("\n%d",&head1);
                            enqueue(head1);
                            printf("Enter the queue of disk positions to be read\n");
                            for(int i=0;i<n1;i++)
                            {
                                scanf("%d",&ele1);
                                enqueue(ele1);
                            }
                            
                            break;
                        
                        }
                        case 2:
                        {
                            FCFS();
                            break;
                        }
                        case 3:
                        {
                            display_FCFS();
                            break;
                        }
                        case 4:
                        {
                            status_FCFS=0;
                            break;
                        }
                        default:
                        printf("\nInvalid choice.Try again!");
                        
                    }
                }
                break;
            }
            
            
             case 2:
            {
                 while(status_FCLS==1)
                 {
                    printf("\nFCLS Disk scheduling is done in the following order:\n1.Input cylinders\n2.Disk scheduling\n3.View seek time taken for the disk scheduling\nWhat do you want to do-\n1.Input cylinders,\n2.Do the FCLS Scheduling,\n3.Display,\n4.Exit");
                    scanf("%d",&ch3);
                    switch(ch3)
                    {
                        case 1:
                        {
                            
                            printf("\nEnter the size of stack request:");
                            scanf("%d",&n2);
                            
                            printf("Enter the stack of disk positions to be read\n");
                            for(int i=0;i<n2;i++)
                            {
                                scanf("%d",&ele2);
                                push(ele2);
                            }
                            printf("\nEnter the initial head position:");
                            scanf("\n%d",&head2);
                            push(head2);
                            break;
                           
                        }
                        case 2:
                        {
                            FCLS();
                            break;
                        }
                        case 3:
                        {
                            display_FCLS();
                            break;
                        }
                        case 4:
                        {
                            status_FCLS=0;
                            break;
                        }
                        default:
                        printf("\nInvalid choice.Try again!");
                        
                    }
                }
                break;
            }
            case 3:
            {
                status_whole=0;
                break;
            }
            default:
            printf("\nInvalid choice..Try again!");
     }
        
    }
    
}
    
       


