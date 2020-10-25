#pragma once

namespace lrm::Util {
inline void safe_memcpy(void* dest, const void* src, size_t size) {
  if (dest == nullptr or src == nullptr or size == 0) return;
  std::memcpy(dest, src, size);
}

inline std::vector<std::byte> str_to_bytes(std::string_view str) {
  auto result = std::vector<std::byte>(str.size());
  safe_memcpy(result.data(), str.data(), str.size());
  return result;
}
}
