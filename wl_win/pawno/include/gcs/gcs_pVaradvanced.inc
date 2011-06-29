/*
								The MIT License  
								
	Copyright (c) <2010> <yezizhu>  
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:  

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.  
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.  
	==================================
	��Ȩ(c) <2010> <yezizhu>  

	ʹ�ø�����֤����������������Ȩ�ޣ���ѣ��κ��˿��Եõ����������������ĵ���һ��������
	���Ҿ�Ӫ�����������κ����ƣ����������Ƶ�ʹ�á����ơ��޸ġ��ϲ������桢���С����Ŵ���֤�顢���߳��۸������Ŀ�����Ȩ����
	ͬʱ���������Щ�������û�������ЩȨ����ʹ����������������  
	
	���ϵİ�Ȩ֪ͨ��Ȩ��֪ͨӦ�ð��������и������Ŀ����л�������������������ʵ�����С�
	
	�������������������ṩ��û���κ���ʽ�ĵ�������������ȷ�ػ��߰����ģ�������Щ���ǲ�����ҵ���ʵĵ��������ơ�
	�ʺ�һ���ض�����;���Ҳ����ַ������ߺͰ�Ȩ���������κγ��϶�ʹ�ø������漰���κ�Ҫ���𺦻����������ζ���Ӧ����
	�����������������û���ֻ�Ǻ�ͬ��ʽ��������Ȩ����������ʽ�������������������÷�Χ�ڡ������������ϵ����������ʹ�û�����������������������Ϊ��  
	=====================================   
*/	




#if defined _gcs_pVaradvanced_included
	#endinput
#endif
#define _gcs_pVaradvanced_included
#pragma library gcs_pVaradvanced

/*
#undef PLAYER_VARTYPE_NONE	
#undef PLAYER_VARTYPE_INT
#undef PLAYER_VARTYPE_STRING
#undef PLAYER_VARTYPE_FLOAT
#define PLAYER_VARTYPE_NONE 	GLOBAL_VARTYPE_NONE
#define PLAYER_VARTYPE_INT 		GLOBAL_VARTYPE_INT
#define PLAYER_VARTYPE_STRING 	GLOBAL_VARTYPE_STRING
#define PLAYER_VARTYPE_FLOAT 	GLOBAL_VARTYPE_FLOAT

static
	g_gcs_PVadv_identify[800][128];
gcs_PVadv_setIdentify(slotid,identify[]){
	format(g_gcs_PVadv_identify[slotid],sizeof(g_gcs_PVadv_identify[]),"%s",identify);
}

gcs_PVadv_idenfity_unusedSlot(){
	for(new i,j = sizeof(g_gcs_PVadv_identify[]);i < j;i++){
		if(g_gcs_PVadv_identify[i][0] == '\0') return i;
	}
	return false;
}
gcs_PVadv_isIdentifyExist(identify[]){
	return (GetGVarType(identify,65535) == GLOBAL_VARTYPE_INT);
}
gcs_PVadv_setIdentifyInGVar(identify[]){
	SetGVarInt(identify,0,65535);
}
gcs_PVadv_removeIdFromGVar(identify[]){
	if(GetGVarType(identify) == GLOBAL_VARTYPE_INT){
		DeleteGVar(identify,65535);
	}
}

gcs_PVadv_storeIdentify(identify[]){
	if(!gcs_PVadv_isIdentifyExist(identify)){
		//printf("add %s",identify);
		gcs_PVadv_setIdentifyInGVar(identify);
		gcs_PVadv_setIdentify(gcs_PVadv_idenfity_unusedSlot(),identify);
	}
}


PVadv_SetPVarInt(playerid,identify[],value){
	SetGVarInt(identify,value,playerid);
	gcs_PVadv_storeIdentify(identify);
}
#define SetPVarInt(%1,%2,%3) PVadv_SetPVarInt(%1,%2,%3)
	
PVadv_SetPVarString(playerid,identify[],value[]){
	SetGVarString(identify,value,playerid);
	gcs_PVadv_storeIdentify(identify);
}
#define SetPVarString(%1,%2,%3) PVadv_SetPVarString(%1,%2,%3)

PVadv_SetPVarFloat(playerid,identify[],Float:value){
	SetGVarFloat(identify,value,playerid);
	gcs_PVadv_storeIdentify(identify);
}
#define SetPVarFloat(%1,%2,%3) PVadv_SetPVarFloat(%1,%2,%3)
//#define SetPVarInt(%1,%2,%3) SetGVarInt(%2,%3,%1)
#define GetPVarInt(%1,%2) GetGVarInt(%2,%1)
//#define SetPVarString(%1,%2,%3) SetGVarString(%2,%3,%1)
#define GetPVarString(%1,%2,%3,%4) GetGVarString(%2,%3,%4,%1)
//#define SetPVarFloat(%1,%2,%3) SetGVarFloat(%2,%3,%1)
#define GetPVarFloat(%1,%2) GetGVarFloat(%2,%1)
#define DeletePVar(%1,%2) DeleteGVar(%2,%1)
#define GetPVarsUpperIndex(%1) GetGVarsUpperIndex(%1)
#define GetPVarNameAtIndex(%1,%2,%3,%4) GetGVarNameAtIndex(%2,%3,%4,%1)
#define GetPVarType(%1,%2) GetGVarType(%2,%1) 


#define pVar_si(%1) SetPVarInt(%1)
#define pVar_gi(%1) GetPVarInt(%1)
#define pVar_ss(%1) SetPVarString(%1)
stock pVar_gs(playerid,varname[]){
	new
		g_pVarString[256];
	GetPVarString(playerid, varname, g_pVarString, sizeof(g_pVarString));
	//printf("str:%s",g_pVarString);
	return g_pVarString;
}	
//#define pVar_gs(%1,%2) GetPVarStringEx(%1,%2)
#define pVar_sf(%1) SetPVarFloat(%1)
#define pVar_gf(%1) GetPVarFloat(%1)
#define pVar_delete(%1) DeletePVar(%1)
#define pVar_exist(%1) GetPVarType(%1)

#define pV_si(%1) SetPVarInt(%1)
#define pV_gi(%1) GetPVarInt(%1)
#define pV_ss(%1) SetPVarString(%1)
stock pV_gs(playerid,varname[]){
	new
		g_pVarString[256];
	GetPVarString(playerid, varname, g_pVarString, sizeof(g_pVarString));
	//printf("str:%s",g_pVarString);
	return g_pVarString;
}	
//#define pV_gs(%1,%2) GetPVarStringEx(%1,%2)
#define pV_sf(%1) SetPVarFloat(%1)
#define pV_gf(%1) GetPVarFloat(%1)
#define pV_delete(%1) DeletePVar(%1)
#define pV_exist(%1) GetPVarType(%1)


PVadv_OnPlayerDisconnect(playerid){
	SetTimerEx("PVadv_plrdisconnect",500,false,"i",playerid);
}

forward PVadv_plrdisconnect(playerid);
public PVadv_plrdisconnect(playerid){
	for(new i,j = sizeof(g_gcs_PVadv_identify[]);i < j;i++){
		if(g_gcs_PVadv_identify[i][0] != '\0'){
			if(gcs_PVadv_isIdentifyExist(g_gcs_PVadv_identify[i])){
				//printf ("remove %s %d",g_gcs_PVadv_identify[i],playerid);
				DeleteGVar(g_gcs_PVadv_identify[i],playerid);
			}
		}
	}
}
*/