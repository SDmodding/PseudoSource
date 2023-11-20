// File Line: 80
// RVA: 0xEEE794
void __fastcall OSuite::psock::crypto::randomize(void *data, unsigned __int64 len)
{
  get_random(len, (char *)data);
}

