Employee * readEmployeeInfo(FILE * fp)
{
    if(!feof(fp))
    {
        int size, i;
        fscanf(fp, "%d\n", &size);

        int * emps = (int *)malloc(sizeof(Employee) * size + sizeof(int));

        if(emps == NULL)
        {
            printf("*** ERROR: Failed to allocate memory. ***\n");
            return NULL;
        }


        *emps = size;
        emps++;

        for(i = 0; i < size; i++)
        {
            if(!feof(fp))
            {
                fscanf(fp, "%d, %d, %f\n", &(((Employee *)emps + i)->id), &(((Employee *)emps + i)->jobType), &(((Employee *)emps + i)->salary));
            }
        }
            return (Employee *)emps;
    }
    else
        return NULL;
}

void saveEmployeeInfo(FILE * fp, Employee * emps)
{
    fprintf(fp, "%d\n", getEmployeeCount(emps));
    int i;
    for(i = 0; i < getEmployeeCount(emps); i++)
    {
        fprintf(fp, "%d, %d, %.2f\n", emps[i].id, emps[i].jobType, emps[i].salary);
    }
    return;
}

Employee * getEmployeeByID(Employee * emps, int id)
{
    int i;
    for(i = 0; i < getEmployeeCount(emps); i++)
    {
        if(emps[i].id == id)
            return &(emps[i]);
    }
    printf("*** ERROR: ID not found. ***\n");
    return NULL;
}

int getEmployeeCount(Employee * emps)
{
        return *((int *)emps - 1);
}


void freeEmployees(Employee * emps)
{
    free((void *)((int *)emps - 1));
    return;
}


void setID(Employee * p, int id)
{
        p->id = id;
        return;
}

int getID(Employee * p)
{
    return p->id;
}

void setJobType(Employee * p, int type)
{
    p->jobType = type;
    return;
}

int getJobType(Employee * p)
{
    return p->jobType;
}

void setSalary(Employee * p, float salary)
{
    p->salary = salary;
    return;
}

float getSalary(Employee * p)
{
    return p->salary;
}
