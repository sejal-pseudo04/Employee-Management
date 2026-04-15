#include<stdio.h>
#include<string.h>
struct employee
{
	char name[100];
	int id;
	char cont_no[15];
	int salary;
};
int main()
{
	struct employee s[5];
	int i;
	int n;
	int e;
	int search_id;
	char new_contact[15];
	int found = 0;
	int c;
	printf("Enter Number of employees:");
	fflush(stdout);
	scanf("%d", &e);
	printf("Enter the details for %d employees:\n", e);
	fflush(stdout);
	for (i=0; i<e; i++)
	{
		printf("\nEmployee %d:\n", i+1);
		printf("Enter Name: ");
		fflush(stdout);
		scanf("%s", s[i].name);
		printf("Enter Employee-ID: ");
		fflush(stdout);
		scanf("%d", &s[i].id);
		printf("Enter Contact Number: ");
		fflush(stdout);
		scanf("%s", s[i].cont_no);
		printf("Enter Salary: ");
		fflush(stdout);
		scanf("%d", &s[i].salary);
	}
	printf("\nSelect from the following options :\n1. Display all\n2. Search by ID\n3. Salary > 10000\n4. Update Contact No\n5. Exit\n");
	fflush(stdout);
	scanf("%d",&c);
	switch (c)
	{
	case 1:
		printf("\n--- Details of All Employees ---\n");
		printf("Name\tID\tContact No\tSalary\n");
		for (i=0; i<e; i++)
		{
			printf("%s", s[i].name);
			printf("\t%d", s[i].id);
			printf("\t%s", s[i].cont_no);
			printf("\t%d\n", s[i].salary);
		}
		break;
	case 2:
		printf("Enter the Employee ID to search: ");
		fflush(stdout);
		scanf("%d", &search_id);
		found = 0;
		for (i=0; i<e; i++)
		{
			if(s[i].id == search_id)
			{
				printf("\n--- Employee Found ---\n");
				printf("Name: %s\n", s[i].name);
				printf("ID: %d\n", s[i].id);
				printf("Contact No: %s\n", s[i].cont_no);
				printf("Salary: %d\n", s[i].salary);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			printf("Employee with ID %d not found.\n", search_id);
		}
		break;
	case 3:
		n = 10000;
		printf("\n--- Employees with Salary more than %d ---\n", n);
		found = 0;
		for (i=0; i<e; i++)
		{
			if(s[i].salary > n)
			{
				printf("Name: %s, ID: %d, Salary: %d\n", s[i].name, s[i].id, s[i].salary);
				found = 1;
			}
		}
		if (!found)
		{
			printf("No employees found with salary greater than %d.\n", n);
		}
		break;
	case 4:
		printf("Enter the Employee ID to update contact number: ");
		fflush(stdout);
		scanf("%d", &search_id);
		found = 0;
		for (i=0; i<e; i++)
		{
			if(s[i].id == search_id)
			{
				printf("Employee %s found. Current Contact No: %s\n", s[i].name, s[i].cont_no);
				printf("Enter the NEW Contact Number: ");
				fflush(stdout);
				scanf("%s", new_contact);
				strcpy(s[i].cont_no, new_contact);
				printf("Successfully updated contact number for %s (ID: %d) to: %s\n", s[i].name, s[i].id, s[i].cont_no);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			printf("Employee with ID %d not found. Contact number NOT updated.\n", search_id);
		}
		break;
	default:
		printf("Invalid choice. Please select a valid option (1-4).\n");
		break;
	}
	return 0;
}

