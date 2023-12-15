#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>




int handle;
typedef char PACKAGENAME;
long int get_module_base(int pid, const char *module_name)
{
	FILE *fp;
	long addr = 0;
	char *pch;
	char filename[32];
	char line[1024];
	snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		while (fgets(line, sizeof(line), fp))
		{
			if (strstr(line, module_name))
			{
				pch = strtok(line, "-");
				addr = strtoul(pch, NULL, 16);
				break;
			}
		}
		fclose(fp);
	}
	return addr;
}

int DIPOKMODS_FLOAT(long int addr, float value)
{
	pwrite64(handle, &value, 4, addr);
	return 0;
}

int DIPOKMODS_DWORD(long int addr, int value)
{
	pwrite64(handle, &value, 4, addr);
	return 0;
}

int getPID(PACKAGENAME * PackageName)
{
	DIR *dir = NULL;
	struct dirent *ptr = NULL;
	FILE *fp = NULL;
	char filepath[256];
	char filetext[128];
	dir = opendir("/proc");
	if (NULL != dir)
	{
		while ((ptr = readdir(dir)) != NULL)
		{

			if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
				continue;
			if (ptr->d_type != DT_DIR)
				continue;
			sprintf(filepath, "/proc/%s/cmdline", ptr->d_name);
			fp = fopen(filepath, "r");
			if (NULL != fp)
			{
				fgets(filetext, sizeof(filetext), fp);
				if (strcmp(filetext, PackageName) == 0)
				{

					break;
				}
				fclose(fp);
			}
		}
	}
	if (readdir(dir) == NULL)
	{
		return 0;
	}
	closedir(dir);
	return atoi(ptr->d_name);
}

int rebootsystem() {
	return system("su -c 'reboot'");
}


int main(int argc, char **argv)
{
	int gs;
    void *jg;
	FILE *fp;
	char ch, wjm[51];
	
	{
		
	}
	int ipid = getPID("com.pubg.imobile");
	if (ipid == 0)
	{
					puts("Game is not Running \n");
					exit(1);
	}


	char lj[64];
	sprintf(lj, "/proc/%d/mem", ipid);
	handle = open(lj, O_RDWR);
	if (handle == -1)
	{
		 exit(1);
	}
	puts("Join TG : @DIPOK_MODS");
	char mname[] = "libUE4.so";
	char nname[] = "libanogs.so";
	char oname[] = "libhdmpve.so";
	char pname[] = "libgcloud.so";
	char qname[] = "libTdatamaster.so";
	long int UE4 = get_module_base(ipid, mname);
	long int anogs = get_module_base(ipid, nname);
	long int hdmpve = get_module_base(ipid, oname);
	long int gcloud = get_module_base(ipid, pname);
	long int Tdatamaster = get_module_base(ipid, qname);

DIPOKMODS_DWORD(anogs + 0xc3520, 0); 
DIPOKMODS_DWORD(anogs + 0xc3550, 0);
DIPOKMODS_DWORD(anogs + 0xc3610, 0);
DIPOKMODS_DWORD(anogs + 0xc3648, 0);
DIPOKMODS_DWORD(anogs + 0xc3654, 0);
DIPOKMODS_DWORD(anogs + 0xc3694, 0);
DIPOKMODS_DWORD(anogs + 0xc36f0, 0);
DIPOKMODS_DWORD(anogs + 0xc3778, 0);
DIPOKMODS_DWORD(anogs + 0xc37a0, 0);
DIPOKMODS_DWORD(anogs + 0xc37b0, 0);
DIPOKMODS_DWORD(anogs + 0xc37e4, 0);
DIPOKMODS_DWORD(anogs + 0xc3800, 0);
DIPOKMODS_DWORD(anogs + 0xc3808, 0);
DIPOKMODS_DWORD(anogs + 0xc382c, 0);
DIPOKMODS_DWORD(anogs + 0xc3874, 0);
DIPOKMODS_DWORD(anogs + 0xc38c0, 0);
DIPOKMODS_DWORD(anogs + 0xc38fc, 0);
DIPOKMODS_DWORD(anogs + 0xc396c, 0);
DIPOKMODS_DWORD(anogs + 0xc398c, 0);
DIPOKMODS_DWORD(anogs + 0xc39a0, 0);
DIPOKMODS_DWORD(anogs + 0xc39ec, 0);
DIPOKMODS_DWORD(anogs + 0xc3b08, 0);
DIPOKMODS_DWORD(anogs + 0xc3b80, 0);
DIPOKMODS_DWORD(anogs + 0xc3b88, 0);
DIPOKMODS_DWORD(anogs + 0xc3c24, 0);
DIPOKMODS_DWORD(anogs + 0xc3c70, 0);
DIPOKMODS_DWORD(anogs + 0xc3c84, 0);
DIPOKMODS_DWORD(anogs + 0xc3c8c, 0);
DIPOKMODS_DWORD(anogs + 0xc3c98, 0);
DIPOKMODS_DWORD(anogs + 0xc3cb4, 0);
DIPOKMODS_DWORD(anogs + 0xc3cbc, 0);
DIPOKMODS_DWORD(anogs + 0xc3cf8, 0);
DIPOKMODS_DWORD(anogs + 0xc3d00, 0);
DIPOKMODS_DWORD(anogs + 0xc3d10, 0);
DIPOKMODS_DWORD(anogs + 0xc3d14, 0);
DIPOKMODS_DWORD(anogs + 0xc3d2c, 0);
DIPOKMODS_DWORD(anogs + 0xc3d34, 0);
DIPOKMODS_DWORD(anogs + 0xc3d58, 0);

	close(handle);
	return 0;
}


