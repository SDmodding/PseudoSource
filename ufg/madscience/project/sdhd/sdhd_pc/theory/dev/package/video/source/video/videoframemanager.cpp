// File Line: 19
// RVA: 0x81AE0
void __fastcall VideoFrameManager::FrameDataCallback(char *rgba, unsigned int width, unsigned int height)
{
  unsigned int v3; // ebx
  unsigned int v4; // edi
  char *v5; // rsi
  Broadcaster *v6; // rax

  v3 = height;
  v4 = width;
  v5 = rgba;
  v6 = Broadcaster::GetBroadcaster();
  Broadcaster::SubmitFrame(v6, v5, v4, v3);
}

