// File Line: 17
// RVA: 0xE76D60
void hkProcessRegisterUtil::registerAllCommonProcesses(void)
{
  hkDebugDisplayProcess::registerProcess();
  hkStatisticsProcess::registerProcess();
  hkInspectProcess::registerProcess();
  hkRemoteObjectProcess::registerProcess();
  hkMemorySnapshotProcess::registerProcess();
}

