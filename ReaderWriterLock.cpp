pthread_mutex_t count_mutex;
pthread_mutex_t write_mutex;
int read_count = 0;

void read_lock() {
  pthread_mutex_lock(count_mutex);
  read_count++;
  if (read_count == 1) {
    pthread_mutex_lock(write_mutex);
  }
  pthread_mutex_unlock(count_mutex);  
}

void read_unlock() {
  pthread_mutex_lock(count_mutex);
  read_count--;
  if (read_count == 0) {
    pthread_mutex_unlock(write_mutex);
  }
  pthread_mutex_unlock(count_mutex);
}

void write_lock() {
  pthread_mutex_lock(write_mutex);
}

void write_unlock() {
  pthread_mutex_unlock(write_mutex);
}
