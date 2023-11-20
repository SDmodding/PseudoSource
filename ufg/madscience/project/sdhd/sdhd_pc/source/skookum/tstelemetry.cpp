// File Line: 37
// RVA: 0x1531050
__int64 dynamic_initializer_for__UFG::TSTelemetry::mSendTelemetryThread__()
{
  UFG::qThread::qThread(&UFG::TSTelemetry::mSendTelemetryThread, "TSTelemetryThread");
  return atexit(dynamic_atexit_destructor_for__UFG::TSTelemetry::mSendTelemetryThread__);
}

// File Line: 41
// RVA: 0x50F7E0
void __fastcall UFG::TSTelemetry::SendTelemetry(void *param)
{
  UFG::OSuiteDBLogger *v1; // r15
  char *v2; // r8
  const char *v3; // rdx
  char *v4; // rbx
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r14
  char *v7; // rbx
  char *v8; // rdi
  char *v9; // rsi
  UFG::qString v10; // [rsp+30h] [rbp-D0h]
  _ULARGE_INTEGER FreeBytesAvailableToCaller; // [rsp+58h] [rbp-A8h]
  _ULARGE_INTEGER TotalNumberOfFreeBytes; // [rsp+60h] [rbp-A0h]
  __int64 v13; // [rsp+68h] [rbp-98h]
  char dest; // [rsp+70h] [rbp-90h]
  int Dst; // [rsp+F0h] [rbp-10h]
  unsigned int v16; // [rsp+F4h] [rbp-Ch]
  unsigned int v17; // [rsp+F8h] [rbp-8h]
  int v18; // [rsp+100h] [rbp+0h]
  UFG::qString v19; // [rsp+190h] [rbp+90h]
  char v20; // [rsp+1C0h] [rbp+C0h]
  char v21; // [rsp+1C1h] [rbp+C1h]
  char v22; // [rsp+1C2h] [rbp+C2h]
  _MEMORYSTATUSEX Buffer; // [rsp+230h] [rbp+130h]
  char Data; // [rsp+270h] [rbp+170h]
  char RootPathName; // [rsp+12B8h] [rbp+11B8h]
  char v26; // [rsp+12B9h] [rbp+11B9h]
  char v27; // [rsp+12BAh] [rbp+11BAh]
  char v28; // [rsp+12BBh] [rbp+11BBh]
  _ULARGE_INTEGER cbData; // [rsp+12C0h] [rbp+11C0h]
  HKEY hKey; // [rsp+12C8h] [rbp+11C8h]

  v13 = -2i64;
  v1 = UFG::OSuiteDBLogger::Instance();
  if ( !UFG::OSuiteDBLogger::CreateMetric(v1, "NewGameConfiguration") )
    return;
  UFG::qString::qString(&v19);
  RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, 1u, &hKey);
  if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, 1u, &hKey)
    || (cbData.LowPart = 4096, RegQueryValueExA(hKey, "ProcessorNameString", 0i64, 0i64, &Data, (LPDWORD)&cbData)) )
  {
    UFG::qSPrintf(&dest, 128, "s_%s", "CPU");
    v2 = "Unknown";
  }
  else
  {
    UFG::qSPrintf(&dest, 128, "s_%s", "CPU");
    v2 = &Data;
  }
  OSuite::ZMetric::SetProperty(v1->m_pMetric, &dest, v2);
  UFG::qString::qString(&v10);
  memset(&Dst, 0, 0x94ui64);
  Dst = 148;
  GetVersionExA((LPOSVERSIONINFOA)&Dst);
  switch ( v16 )
  {
    case 4u:
      if ( v17 )
      {
        if ( v17 == 10 )
        {
          v3 = "Windows 98";
        }
        else if ( v17 == 90 )
        {
          v3 = "Windows ME";
        }
        else
        {
          v3 = "Unknown version of Windows NT 4";
        }
      }
      else
      {
        v3 = "Windows 95";
        if ( v18 != 1 )
          v3 = "Windows NT 4";
      }
      goto LABEL_32;
    case 5u:
      if ( v17 )
      {
        if ( v17 == 1 )
        {
          v3 = "Windows XP";
        }
        else if ( v17 == 2 )
        {
          v3 = "Windows Server 2003 or Windows XP Professional";
        }
        else
        {
          v3 = "Unknown version of Windows NT 5";
        }
      }
      else
      {
        v3 = "Windows 2000";
      }
      goto LABEL_32;
    case 6u:
      if ( v17 )
      {
        if ( v17 == 1 )
        {
          v3 = "Windows 7";
        }
        else
        {
          if ( v17 != 2 )
          {
            UFG::qString::Format(&v10, "Unknown version of Windows NT 6 - (minor version:%d)");
            goto LABEL_33;
          }
          v3 = "Windows 8";
        }
      }
      else
      {
        v3 = "Windows Vista";
      }
LABEL_32:
      UFG::qString::Format(&v10, v3);
      goto LABEL_33;
  }
  UFG::qString::Format(&v10, "Unknown version of Windows NT - (version:%d, minor version:%d)", v16, v17);
LABEL_33:
  v4 = v10.mData;
  UFG::qSPrintf(&dest, 128, "s_%s", "OS");
  OSuite::ZMetric::SetProperty(v1->m_pMetric, &dest, v4);
  Buffer.dwLength = 64;
  GlobalMemoryStatusEx(&Buffer);
  v5 = Buffer.ullTotalPhys >> 30;
  UFG::qSPrintf(&dest, 128, "i32_%s", "RAM");
  OSuite::ZMetric::SetProperty(v1->m_pMetric, &dest, v5);
  GetLogicalDriveStringsA(0x64u, &v20);
  v28 = 0;
  v6 = 0i64;
  if ( v20 )
  {
    v7 = &v20;
    v8 = &v22;
    v9 = &v21;
    do
    {
      RootPathName = *v7;
      v26 = *v9;
      v27 = *v8;
      v9 += 4;
      v8 += 4;
      v7 += 4;
      if ( GetDriveTypeA(&RootPathName) == 3 )
      {
        FreeBytesAvailableToCaller.QuadPart = 0i64;
        cbData.QuadPart = 0i64;
        TotalNumberOfFreeBytes.QuadPart = 0i64;
        GetDiskFreeSpaceExA(&RootPathName, &FreeBytesAvailableToCaller, &cbData, &TotalNumberOfFreeBytes);
        v6 += cbData.QuadPart;
      }
    }
    while ( *v7 );
  }
  UFG::qSPrintf(&dest, 128, "i64_%s", "HDSpace");
  OSuite::ZMetric::SetProperty(v1->m_pMetric, &dest, v6 >> 30);
  UFG::qSPrintf(&dest, 128, "s_%s", "GraphicsCard");
  OSuite::ZMetric::SetProperty(v1->m_pMetric, &dest, Render::gVideoCardDesc);
  UFG::OSuiteDBLogger::SubmitMetric(v1, 0);
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&v19);
}

// File Line: 184
// RVA: 0x4ECF30
void __fastcall UFG::TSTelemetry::MthdC_send_new_game_telemetry(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&UFG::TSTelemetry::mSendTelemetryThread, 0x8000u);
  UFG::qThread::Start(&UFG::TSTelemetry::mSendTelemetryThread, UFG::TSTelemetry::SendTelemetry, 0i64);
}

