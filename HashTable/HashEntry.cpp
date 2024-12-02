template <typename E>
class HashEntry
{
public:
    E value;
    HashEntry(E value)
    {
        (*this).value = value;
    }
};