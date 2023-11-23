// File Line: 30
// RVA: 0xEEA7B0
bool __fastcall OSuite::TOperatorComparer<void *>::Equals(
        OSuite::TOperatorComparer<unsigned __int64> *this,
        const unsigned __int64 *v1,
        const unsigned __int64 *v2)
{
  return *v1 == *v2;
}

// File Line: 35
// RVA: 0xED7154
bool __fastcall OSuite::TOperatorComparer<OSuite::ZUrl>::LessThan(
        OSuite::TOperatorComparer<OSuite::ZUrl> *this,
        OSuite::ZUrl *v1,
        OSuite::ZUrl *v2)
{
  return OSuite::ZUrl::operator<(v1, v2);
}

