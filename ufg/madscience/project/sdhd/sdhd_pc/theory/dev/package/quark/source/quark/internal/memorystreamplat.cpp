// File Line: 23
// RVA: 0xA37950
void __fastcall UFG::qMemoryStreamer::BeginRawReadPlat(
        UFG::qMemoryStreamer *this,
        const char *stream_name,
        void *local_mem,
        unsigned __int64 local_num_bytes,
        void *main_mem,
        size_t main_num_bytes)
{
  memmove(local_mem, main_mem, (unsigned int)main_num_bytes);
}

// File Line: 35
// RVA: 0xA37970
void __fastcall UFG::qMemoryStreamer::BeginRawWritePlat(
        UFG::qMemoryStreamer *this,
        const char *stream_name,
        void *local_mem,
        unsigned __int64 local_num_bytes,
        void *main_mem,
        size_t main_num_bytes)
{
  memmove(main_mem, local_mem, (unsigned int)main_num_bytes);
}

