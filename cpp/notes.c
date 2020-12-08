// Nothing here is actually working code -- just snippets reminding me of
// how some things work.


// Returns an iterator pointing to the first element in the range
// greater or equal to value, or last if no such element is found.
auto lower = std::lower_bound(data.begin(), data.end(), value);