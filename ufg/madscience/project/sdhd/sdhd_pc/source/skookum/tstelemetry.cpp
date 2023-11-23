// File Line: 37
// RVA: 0x1531050
__int64 dynamic_initializer_for__UFG::TSTelemetry::mSendTelemetryThread__()
{
  UFG::qThread::qThread(&UFG::TSTelemetry::mSendTelemetryThread, "TSTelemetryThread");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TSTelemetry::mSendTelemetryThread__);
}

// File Line: 41
// RVA: 0x50F7E0
void __fastcall UFG::TSTelemetry::SendTelemetry(void *param)
{
  UFG::OSuiteDBLogger *v1; // r15
  char *v2; // r8
  const char *v3; // rdx
  char *mData; // rbx
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r14
  char *v7; // rbx
  char *v8; // rdi
  char *v9; // rsi
  UFG::qString v10; // [rsp+30h] [rbp-D0h] BYREF
  _ULARGE_INTEGER FreeBytesAvailableToCaller; // [rsp+58h] [rbp-A8h] BYREF
  _ULARGE_INTEGER TotalNumberOfFreeBytes; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v13; // [rsp+68h] [rbp-98h]
  char dest[128]; // [rsp+70h] [rbp-90h] BYREF
  _OSVERSIONINFOA Dst; // [rsp+F0h] [rbp-10h] BYREF
  UFG::qString v16; // [rsp+190h] [rbp+90h] BYREF
  char v17; // [rsp+1C0h] [rbp+C0h] BYREF
  char v18; // [rsp+1C1h] [rbp+C1h] BYREF
  char v19; // [rsp+1C2h] [rbp+C2h] BYREF
  _MEMORYSTATUSEX Buffer; // [rsp+230h] [rbp+130h] BYREF
  char Data[4144]; // [rsp+270h] [rbp+170h] BYREF
  char RootPathName; // [rsp+12B8h] [rbp+11B8h] BYREF
  char v23; // [rsp+12B9h] [rbp+11B9h]
  char v24; // [rsp+12BAh] [rbp+11BAh]
  char v25; // [rsp+12BBh] [rbp+11BBh]
  _ULARGE_INTEGER cbData; // [rsp+12C0h] [rbp+11C0h] BYREF
  HKEY hKey; // [rsp+12C8h] [rbp+11C8h] BYREF

  v13 = -2i64;
  v1 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v1, "NewGameConfiguration") )
  {
    UFG::qString::qString(&v16);
    RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, 1u, &hKey);
    if ( RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, 1u, &hKey)
      || (cbData.LowPart = 4096, RegQueryValueExA(hKey, "ProcessorNameString", 0i64, 0i64, Data, (LPDWORD)&cbData)) )
    {
      UFG::qSPrintf(dest, 128, "s_%s", "CPU");
      v2 = "Unknown";
    }
    else
    {
      UFG::qSPrintf(dest, 128, "s_%s", "CPU");
      v2 = Data;
    }
    OSuite::ZMetric::SetProperty(v1->m_pMetric, dest, v2);
    UFG::qString::qString(&v10);
    memset(&Dst, 0, sizeof(Dst));
    Dst.dwOSVersionInfoSize = 148;
    GetVersionExA(&Dst);
    switch ( Dst.dwMajorVersion )
    {
      case 4u:
        if ( Dst.dwMinorVersion )
        {
          if ( Dst.dwMinorVersion == 10 )
          {
            UFG::qString::Format(&v10, "Windows 98");
          }
          else if ( Dst.dwMinorVersion == 90 )
          {
            UFG::qString::Format(&v10, "Windows ME");
          }
          else
          {
            UFG::qString::Format(&v10, "Unknown version of Windows NT 4");
          }
        }
        else
        {
          v3 = "Windows 95";
          if ( Dst.dwPlatformId != 1 )
            v3 = "Windows NT 4";
          UFG::qString::Format(&v10, v3);
        }
        break;
      case 5u:
        if ( Dst.dwMinorVersion )
        {
          if ( Dst.dwMinorVersion == 1 )
          {
            UFG::qString::Format(&v10, "Windows XP");
          }
          else if ( Dst.dwMinorVersion == 2 )
          {
            UFG::qString::Format(&v10, "Windows Server 2003 or Windows XP Professional");
          }
          else
          {
            UFG::qString::Format(&v10, "Unknown version of Windows NT 5");
          }
        }
        else
        {
          UFG::qString::Format(&v10, "Windows 2000");
        }
        break;
      case 6u:
        if ( Dst.dwMinorVersion )
        {
          if ( Dst.dwMinorVersion == 1 )
          {
            UFG::qString::Format(&v10, "Windows 7");
          }
          else if ( Dst.dwMinorVersion == 2 )
          {
            UFG::qString::Format(&v10, "Windows 8");
          }
          else
          {
            UFG::qString::Format(&v10, "Unknown version of Windows NT 6 - (minor version:%d)", Dst.dwMinorVersion);
          }
        }
        else
        {
          UFG::qString::Format(&v10, "Windows Vista");
        }
        break;
      default:
        UFG::qString::Format(
          &v10,
          "Unknown version of Windows NT - (version:%d, minor version:%d)",
          Dst.dwMajorVersion,
          Dst.dwMinorVersion);
        break;
    }
    mData = v10.mData;
    UFG::qSPrintf(dest, 128, "s_%s", "OS");
    OSuite::ZMetric::SetProperty(v1->m_pMetric, dest, mData);
    Buffer.dwLength = 64;
    GlobalMemoryStatusEx(&Buffer);
    v5 = Buffer.ullTotalPhys >> 30;
    UFG::qSPrintf(dest, 128, "i32_%s", "RAM");
    OSuite::ZMetric::SetProperty(v1->m_pMetric, dest, v5);
    GetLogicalDriveStringsA(0x64u, &v17);
    v25 = 0;
    v6 = 0i64;
    if ( v17 )
    {
      v7 = &v17;
      v8 = &v19;
      v9 = &v18;
      do
      {
        RootPathName = *v7;
        v23 = *v9;
        v24 = *v8;
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
    UFG::qSPrintf(dest, 128, "i64_%s", "HDSpace");
    OSuite::ZMetric::SetProperty(v1->m_pMetric, dest, v6 >> 30);
    UFG::qSPrintf(dest, 128, "s_%s", "GraphicsCard");
    OSuite::ZMetric::SetProperty(v1->m_pMetric, dest, Render::gVideoCardDesc);
    UFG::OSuiteDBLogger::SubmitMetric(v1, 0);
    UFG::qString::~qString(&v10);
    UFG::qString::~qString(&v16);
  }
}

// File Line: 184
// RVA: 0x4ECF30
void __fastcall UFG::TSTelemetry::MthdC_send_new_game_telemetry(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&UFG::TSTelemetry::mSendTelemetryThread, 0x8000u);
  UFG::qThread::Start(&UFG::TSTelemetry::mSendTelemetryThread, UFG::TSTelemetry::SendTelemetry, 0i64);
}

