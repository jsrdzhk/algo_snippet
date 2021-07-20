/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-15 17:31:10
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-15 17:31:50
 */
namespace smart_ptr {
class counter {
   public:
    counter(unsigned cnt) : count_(cnt) {}

    unsigned& operator++() {
        ++count_;
        return count_;
    }

    unsigned operator++(int) {
        unsigned count = count_;
        ++count_;
        return count;
    }

    unsigned& operator--() {
        --count_;
        return count_;
    }

    unsigned operator--(int) {
        unsigned count = count_;
        --count_;
        return count;
    }
    unsigned getCount() const { return count_; }

   private:
    unsigned count_ = 0;
};

template <typename T>
class shared_ptr {
   public:
    using pointer = T*;
    using reference = T&;
    shared_ptr(pointer ptr) {
        counter_ = new counter(1);
        data_ = ptr;
    }
    ~shared_ptr() {
        --(*counter_);
        if (counter_->getCount() == 0) {
            delete data_;
            data_ = nullptr;
            delete counter_;
            counter_ = nullptr;
        }
    }

    shared_ptr(const shared_ptr<T>& s_ptr) {
        counter_ = s_ptr.counter_;
        ++(*counter_);
        data_ = s_ptr.data_;
    }

    pointer get() const { return data_; }

    unsigned use_count() const { return counter_->count_; }
    pointer operator->() { return data_; }

    reference operator*() { return *data_; }

   private:
    counter* counter_;
    pointer data_;
};
}  // namespace smart_ptr