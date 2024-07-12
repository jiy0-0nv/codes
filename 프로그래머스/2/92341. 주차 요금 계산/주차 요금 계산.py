class Car:
    def __init__(self, in_time):
        self.in_time = in_time[0] * 60 + in_time[1]
        self.out_time = 23 * 60 + 59
        self.parking_time = 0
        
    def set_in_time(self, in_time):
        self.parking_time += self.out_time - self.in_time
        self.in_time = in_time[0] * 60 + in_time[1]
        self.out_time = 23 * 60 + 59
        
    def set_out_time(self, out_time):
        self.out_time = out_time[0] * 60 + out_time[1]
        
    def get_parking_time(self):
        self.parking_time += self.out_time - self.in_time
        return self.parking_time
    
class Lot:
    def __init__(self, fees):
        self.fees = fees[:]
        self.cars = {}
        self.car_list = []
        
    def read_record(self, record):
        num = int(record[6:10])
        time = [int(record[:2]), int(record[3:5])]            
        if record[11] == "I":
            if num in self.car_list:
                self.cars[num].set_in_time(time)
            else:
                self.car_list.append(num)
                self.cars[num] = Car(time)
        else:
            self.cars[num].set_out_time(time)
        
    def get_fee(self, num):
        time = self.cars[num].get_parking_time()
        fee = self.fees[1]
        if time > self.fees[0]:
            fee += ((time - self.fees[0] - 1) // self.fees[2] + 1) * self.fees[3]
        return fee
        
    def get_sorted_fees(self):
        self.car_list.sort()
        fee_list = []
        for n in self.car_list:
            fee_list.append(self.get_fee(n))
        return fee_list

def solution(fees, records):
    parking_lot = Lot(fees)
    for r in records:
        parking_lot.read_record(r)
    return parking_lot.get_sorted_fees()